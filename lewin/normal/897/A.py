n,m = map(int, raw_input().split())
s = list(raw_input())
for i in range(m):
  l,r,c1,c2 = raw_input().split()
  for j in xrange(int(l)-1,int(r)):
    if s[j] == c1:
      s[j] = c2
print "".join(s)