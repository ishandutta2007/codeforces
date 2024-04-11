n,k = map(int, raw_input().split())
a = map(int, raw_input().split())
have = 0
give = 0
day = 0
while give < k and day < n:
    have += a[day]
    t = min(have, 8)
    have -= t
    give += t
    day += 1
print -1 if give < k else day