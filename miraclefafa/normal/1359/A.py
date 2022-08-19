t=int(input())

for i in range(t):
	n,m,k=map(int,input().split())
	a=min(m,n//k)
	m-=a
	b=(m+k-2)//(k-1)
	print(a-b)