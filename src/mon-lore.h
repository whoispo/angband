/*
 * File: mon-lore.h
 * Purpose: Structures and functions for monster recall.
 *
 * Copyright (c) 1997-2007 Ben Harrison, James E. Wilson, Robert A. Koeneke
 *
 * This work is free software; you can redistribute it and/or modify it
 * under the terms of either:
 *
 * a) the GNU General Public License as published by the Free Software
 *    Foundation, version 2, or
 *
 * b) the "Angband licence":
 *    This software may be copied and distributed for educational, research,
 *    and not for profit purposes provided that this copyright and statement
 *    are included in all such copies.  Other copyrights may also apply.
 */

#ifndef MONSTER_LORE_H
#define MONSTER_LORE_H

#include "monster.h"

/** Constants **/

/** Macros **/

/** Structures **/

/*
 * Monster "lore" information
 *
 * Note that these fields are related to the "monster recall" and can
 * be scrapped if space becomes an issue, resulting in less "complete"
 * monster recall (no knowledge of spells, etc). XXX XXX XXX
 */
typedef struct
{
	s16b sights;			/* Count sightings of this monster */
	s16b deaths;			/* Count deaths from this monster */

	s16b pkills;			/* Count monsters killed in this life */
	s16b tkills;			/* Count monsters killed in all lives */

	byte wake;				/* Number of times woken up (?) */
	byte ignore;			/* Number of times ignored (?) */

	byte drop_gold;			/* Max number of gold dropped at once */
	byte drop_item;			/* Max number of item dropped at once */

	byte cast_innate;		/* Max number of innate spells seen */
	byte cast_spell;		/* Max number of other spells seen */

	byte blows[MONSTER_BLOW_MAX]; /* Number of times each blow type was seen */

	bitflag flags[RF_SIZE]; /* Observed racial flags - a 1 indicates
	                         * the flag (or lack thereof) is known to
	                         * the player */
	bitflag spell_flags[RSF_SIZE];  /* Observed racial spell flags */
} monster_lore;

/** Variables **/

/*
 * Array[z_info->r_max] of monster lore
 */
extern monster_lore *l_list;

/** Functions **/
void cheat_monster_lore(const monster_race *r_ptr, monster_lore *l_ptr);
void wipe_monster_lore(const monster_race *r_ptr, monster_lore *l_ptr);
void lore_do_probe(struct monster *m);
void monster_flags_known(const monster_race *r_ptr, const monster_lore *l_ptr, bitflag flags[RF_SIZE]);
void lore_treasure(struct monster *m_ptr, int num_item, int num_gold);
void lore_title(textblock *tb, const monster_race *r_ptr);
void lore_description(textblock *tb, const monster_race *race, const monster_lore *original_lore, bool spoilers);
void lore_show_interactive(const monster_race *race, const monster_lore *lore);
void lore_show_subwindow(const monster_race *race, const monster_lore *lore);
monster_lore *get_lore(const monster_race *race);
bool lore_save(const char *path);

#endif /* MONSTER_LORE_H */
