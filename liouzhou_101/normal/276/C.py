R=lambda:map(int,raw_input().split());n,q=R();a=sorted(R());b=[0]*n
for i in range(q):
	x,y=R();b[x-1]+=1
	if y<n:b[y]-=1
for i in range(1,n):b[i]+=b[i-1]
b.sort();print sum(b[i]*a[i]for i in range(n))