R=lambda:map(int,raw_input().split())
n,k=R()
a=R()
p=max(a)+2
w=[0]*p
u=[0]*p
for i in xrange(n):
	for j in xrange(i):w[abs(a[i]-a[j])]+=1
for i in xrange(1,p):
	if sum(w[j]for j in xrange(i,p,i))>k*(k+1)/2:continue
	t=0
	for x in a:t,u[x%i]=t+(u[x%i]==i),i
	if t<=k:
		print i
		exit()