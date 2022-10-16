n = int(raw_input())
arr = map(int, raw_input().split())
s = min(arr)
last = -1
ans = n
for i in range(n):
  if arr[i] == s:
    if last != -1:
      ans = min(ans, i - last)
    last = i
print ans