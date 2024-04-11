n,k = map(int, raw_input().split())
arr = map(int, raw_input().split())
ans = k
for x in arr:
  if k % x == 0:
    ans = min(ans, k/x)
print ans