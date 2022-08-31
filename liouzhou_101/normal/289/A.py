R=lambda:map(int,raw_input().split())
n,k=R()
p=0
for i in range(n):
	l,r=R()
	p+=r-l+1
print (k-p%k)%k