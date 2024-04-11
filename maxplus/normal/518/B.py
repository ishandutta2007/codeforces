import sys
import collections

c, d = map(collections.Counter, sys.stdin.readlines())

a = -1
b = 0
for x in [0, 32]:
 for k, v in c.items():
  K = chr(ord(k) ^ x)
  t = min(v, d[K])
  c[k] -= t
  d[K] -= t
  a += t
 a, b = b, a
print(a, b)