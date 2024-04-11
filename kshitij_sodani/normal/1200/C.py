from math import gcd
n,m,q=map(int,input().split())
p=gcd(n,m)
ss={1:n//p,2:m//p}
for _ in range(q):
    a,aa,b,bb=map(int,input().split())
    s=(aa-1)//ss[a]
    t=(bb-1)//ss[b]
    if s==t:
        print("YES")
    else:
        print("NO")