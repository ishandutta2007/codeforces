n,m=map(int,raw_input().split())
f=[]
for i in xrange(n):
	s=raw_input()
	f.append(s)
ans=0
for i in xrange(n-1):
	for j in xrange(m-1):
		if {f[i][j],f[i][j+1],f[i+1][j],f[i+1][j+1]}=={"f","a","c","e"}:
			ans+=1
print ans