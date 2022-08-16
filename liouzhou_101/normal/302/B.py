R=lambda:map(int,raw_input().split())
n,m=R()
a=[R()for i in range(n)]
i=p=0
for v in R():
	while p<v:p,i=p+a[i][0]*a[i][1],i+1
	print i