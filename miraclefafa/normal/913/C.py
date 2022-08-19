n,L=map(int,raw_input().split())
c=map(int,raw_input().split())
for i in xrange(100):
	c.append(10**100)
for i in xrange(40):
	c[i]=min(c[j]*2**(i-j) for j in xrange(i+1))
for i in xrange(40):
	c[i]=min(c[j] for j in xrange(i,40))
ret=10**100
cnt=0
for i in xrange(40,-1,-1):
	if L&(1<<i): cnt+=c[i]
	else: ret=min(ret,cnt+c[i])
#	print i,cnt+c[i],ret
ret=min(ret,cnt)
print ret