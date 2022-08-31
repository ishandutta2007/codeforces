def C(n,m):return p[n]*r[m]*r[n-m]
n,w,b=map(int,raw_input().split())
M=1000000009
p=[1]
r=[]
for i in range(4010):
	p+=[p[i]*(i+1)%M]
	r+=[pow(p[i],M-2,M)]
print sum(p[w]*p[b]*(n-i-1)*C(b-1,i-1)*C(w-1,n-i-1)for i in range(max(1,n-w),min(n-2,b)+1))%M