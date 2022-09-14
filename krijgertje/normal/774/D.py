i=lambda:map(int,input().split())
n,l,r=i()
a=list(i())
b=list(i())
a0=a[0:l-1]
a1=a[l-1:r]
a2=a[r:n]
b0=b[0:l-1]
b1=b[l-1:r]
b2=b[r:n]
a1.sort()
b1.sort()
print("TRUTH" if a0==b0 and a1==b1 and a2==b2 else "LIE")