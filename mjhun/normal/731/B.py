n=int(raw_input())
x=map(int,raw_input().split())

r=True

for i in range(n-1):
  if x[i]%2:
    if not x[i+1]:
      r=False
      break
    x[i+1]-=1
r=r and x[n-1]%2==0
if r:
  print "YES"
else:
  print "NO"