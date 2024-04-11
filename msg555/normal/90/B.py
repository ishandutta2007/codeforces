(n, m) = [int(x) for x in raw_input().split()]
v = [raw_input() for x in xrange(0, n)]

s = ""
for i in xrange(0, n):
  for j in xrange(0, m):
    ok = True
    for k in xrange(0, n):
      ok &= k == i or v[k][j] != v[i][j]
    for k in xrange(0, m):
      ok &= k == j or v[i][k] != v[i][j]
    if ok:
      s += v[i][j]
print s