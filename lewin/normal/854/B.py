n,k = map(int, raw_input().split())
if k == n:
  print "0 0"
else:
  print min(k,1), min(n-k, k*2, (n/3)*2 + (n%3 == 2))