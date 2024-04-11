(n, m, k) = [int(x) for x in raw_input().split()]
A = [int(x) for x in raw_input().split()]

if n % 2 == 0:
  print "0"
else:
  print min(m / ((n + 1) / 2) * k, min([A[x] for x in xrange(0, n, 2)]))