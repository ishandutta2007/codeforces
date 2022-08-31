from fractions import *
from math import *
n,m=map(int,raw_input().split())
a=map(int,raw_input().split())
k=a[0]-1
for i in range(n):
    k=gcd(k,a[i]-1)
def sol(x):
    p=0
    if x%2==1:
        t=x
        while t<m:
            p+=m-t
            t*=2
    return p
p=0
for i in range(1,int(sqrt(k))+1):
    if k%i:
        continue
    p+=sol(i)
    if i*i!=k:
        p+=sol(k/i)
print p