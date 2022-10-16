import sys
import itertools
import copy

input = sys.stdin.readline
for _ in range(int(input())):
  n = int(input())
  b = list(map(int, input().split()))
  s = sum(b)
  if s % (n * (n + 1) // 2):
    print("NO")
    continue
  s //= (n * (n + 1) // 2)
  b = itertools.starmap(int.__sub__, zip(b[-1:] + b[:-1], b))
  b = map(s.__add__, b)
  b = map(n.__rfloordiv__, b)
  if sum(copy.deepcopy(b)) != s or max(copy.deepcopy(b)) > 1e9 or min(copy.deepcopy(b)) < 1:
    print("NO")
    continue
  print("YES")
  print(*b)