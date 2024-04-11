'''input
5
1 6
2 9
2 18
5 24
8 32
8 48
'''
from typing import List, Tuple
from math import sqrt
import sys

cache: List[Tuple[int, int]] = [(0, 0)] * 105
ans = [-1] * 105
last = [-1] * 105
n = int(input())
fi, se = [int(x) for x in input().split(' ')]
cache[0] = (fi, se)


def ask(x: int, id: int):
    print('+', x)
    sys.stdout.flush()
    global fi, se
    nfi, nse = [int(x) for x in input().split(' ')]
    cache[id] = (nfi - fi, nse - se)
    (fi, se) = (nfi, nse)
    last[x] = id


def calTri(x: int) -> int:
    return int(sqrt(x * 2)) + 1


ask(1, 1)
ask(2, 2)
ask(3, 3)
ask(1, n)
if cache[1][1] != 0:
    ans[2] = calTri(cache[2][0])
    ans[3] = calTri(cache[3][0])
else:
    if cache[2][1] != 0:
        ans[2] = 0
        ans[3] = cache[n][1] - 1
    else:
        ans[3] = 0
        ans[2] = cache[n][1] - 1
if cache[1][0] != 0:
    ans[1] = calTri(cache[1][0])
else:
    ans[1] = 1 if cache[n][0] != 0 else 0
# 1 2 3 in 4 question
for i in range(4, n + 1):
    if i == n:
        p = last[n - 1]
        ans[n] = (cache[p][1] - (ans[n - 3] + 1) * (ans[n - 2] + 1)) // (ans[n - 2] + 1)
    else:
        ask(i, i)
        if cache[i - 1][1] == (ans[i - 3] + 1) * (ans[i - 2] + 1):
            ans[i] = 0
        else:
            if cache[i][0] != 0:
                ans[i] = calTri(cache[i][0])
            else:
                ans[i] = 1
print('!', end=' ')
for i in range(1, n + 1):
    print(ans[i], end=' ')
print()
sys.stdout.flush()