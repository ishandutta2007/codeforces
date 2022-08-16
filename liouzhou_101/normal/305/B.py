from fractions import *
R=lambda:map(int,raw_input().split())
p,q=R()
z=gcd(p,q)
n=input()
a=R()
x,y=a[n-1],1
for i in reversed(range(n-1)):
    x,y=y,x
    x+=a[i]*y
if x*q==p*y:
    print "YES"
else:
    print "NO"