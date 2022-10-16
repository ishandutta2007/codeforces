n =int(raw_input())
arr = map(int, raw_input().split())

ans, cur, last = 0, 0, -1000000000
for x in arr:
  if x <= last:
    cur = 0
  cur+= 1
  last = x
  ans =max(ans,cur)
print ans