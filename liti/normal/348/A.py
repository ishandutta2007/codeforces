#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))

a.sort()

lo = a[-1] - 1
hi = sum(a) 

while hi - lo > 1:
    mid = (lo+hi)//2

    games = 0
    for x in a:
        games += mid - x

    if games < mid:
        lo = mid 
    else:
        hi = mid 

print(hi)