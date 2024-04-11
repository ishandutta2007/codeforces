n,l,r=map(int,input().split())
mi=2**l-1+(n-l)
ma=2**r-1+(n-r)*(2**(r-1))
print(mi,ma)