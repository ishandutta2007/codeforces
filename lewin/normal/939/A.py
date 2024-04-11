n = int(raw_input())
arr = map(int, raw_input().split())
for i in range(n):
  if arr[arr[arr[i]-1]-1]-1 == i:
    print "YES"
    break
else:
  print "NO"