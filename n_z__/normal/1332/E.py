n,m,l,r=map(int,input().split())
r-=l-1
if (n*m)&1:
	print(pow(r,n*m,998244353))
else:
	print((pow(r,n*m,998244353)+(r&1))*998244354//2%998244353)