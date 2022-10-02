def gcd(a,b):
    if a<b: a,b=b,a
    return gcd(b,a%b) if b else a

n,a,b,p,q=map(int,input().split())
da=n // a
db=n // b
dab=n // (a*b//gcd(a,b))
da -= dab
db -= dab

print(da * p + db * q + dab * max(p,q))