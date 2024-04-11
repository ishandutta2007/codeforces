import datetime

def tot_days(year):
    if year % 400 == 0: return 366
    if year % 100 == 0: return 365
    if year % 4 == 0: return 366
    return 365

year = int(input())

first_day = 0
tot = tot_days(year)

days = first_day
cyear = year

while True:
    days = (days + tot_days(cyear)) % 7
    cyear += 1

    if first_day == days and tot == tot_days(cyear):
        print(cyear)
        break