n = int(raw_input())
spec = 3
for i in range(n):
  win = int(raw_input())
  if win == spec:
    print "NO"
    break
  spec = (1^2^3)^(win^spec)
else:
  print "YES"