from itertools import permutations
from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


x = []
y = []
for _ in range(3):
    xi, yi = read_ints()
    x.append(xi)
    y.append(yi)

mx = sorted(x)[1]
my = sorted(y)[1]
ans = []
for xi, yi in zip(x, y):
    if xi == mx and yi == my:
        continue
    if xi == mx or yi == my:
        ans.append((xi, yi, mx, my))
    else:
        ans.append((xi, yi, xi, my))
        ans.append((xi, my, mx, my))

print(len(ans))
for sx, sy, tx, ty in ans:
    print(sx, sy, tx, ty)