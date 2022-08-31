from fractions import*
n,m,x,y,a,b=map(int,raw_input().split())
c=gcd(a,b)
a/=c
b/=c
t=min(n/a,m/b)
a*=t
b*=t
X,Y=x-(a+1)/2,y-(b+1)/2
if X<0:X=0
if X+a>n:X=n-a
if Y<0:Y=0
if Y+b>m:Y=m-b
print X,Y,X+a,Y+b