n=int(input())
s=input()
a=s.split()
for i in range(n):
	a[i]=int(a[i])
a.sort()
def gcd(a,b):
    while(b):
    	a%=b
    	a,b=b,a
    return a

ans=0
for i in range(n-1):
	ans=gcd(ans,a[i+1]-a[i])
print((a[n-1]-a[0])//ans-n+1)