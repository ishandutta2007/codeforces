n=input()
a=map(int,raw_input().split())
pmax=[-(1<<30) for i in xrange(61)]
ans=0
for x in a:
	val=0
	for j in xrange(-30,x+1):
		val=max(val,pmax[j])
		pmax[j]=-(1<<30)
	pmax[x]=val+x
	for j in xrange(x+1,31):
		pmax[j]=pmax[j]+x
	for j in xrange(-30,31):
		ans=max(ans,pmax[j]-j)

print ans