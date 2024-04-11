'''input
3
4
1 7 6 5
5
1 2 3 4 5
2
0 -4
'''
import math


def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    mx = arr[0]
    mdis = 0
    for i in range(1, len(arr)):
        mdis = max(mdis, mx - arr[i])
        mx = max(mx, arr[i])
    if mdis == 0:
        return 0
    for i in range(0, 60):
        mdis -= (1 << i)
        if mdis <= 0:
            return (i + 1)


T = int(input())
while T > 0:
    T -= 1
    print(solve())