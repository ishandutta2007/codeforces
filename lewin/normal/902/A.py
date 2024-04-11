n,m = map(int, raw_input().split())
best = 0
for i in range(n):
  a,b = map(int, raw_input().split())
  if best >= a:
    best = max(best, b)
print (best == m) * "YES" or "NO"