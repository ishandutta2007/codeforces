import sys,math
range = xrange
input = raw_input

mod=998244353

n,k=map(int,input().split())
mu=[0]*(n+1)

mu[1]=1

if k>n:
	print 0
	exit(0)
for i in range(1,n+1):
	for j in range(i+i,n+1,i):
		mu[j]-=mu[i]

ans=0
pf=0

comb=[0]*(n+1)

comb[k]=1

for i in xrange(k+1,n+1):
	comb[i]=comb[i-1]*i*pow(i-k,mod-2,mod)%mod

for i in range(1,n+1):
	if n/i!=pf:
		pf=n/i
		pans=comb[pf]-comb[pf-1]

	ans+=pans
ans%=mod
if ans<0:
	ans+=mod
print ans