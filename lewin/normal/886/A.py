arr = map(int, raw_input().split())
s = sum(arr)
for g in range(1<<6):
  q = 0
  m = 0
  for i in range(6):
    if (g >> i) & 1:
      q += arr[i]
      m += 1
  if m == 3 and 2 * q == s:
    print "YES"
    break
else:
  print "NO"