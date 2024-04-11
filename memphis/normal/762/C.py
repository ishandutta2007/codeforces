a=raw_input()
b=raw_input()

n=len(a)
m=len(b)

pa=[0 for _  in xrange(n)]

for i in range(0,n):
    if i==0:
        pa[i]=(int)(a[i]==b[i])
    else:
        if pa[i-1]==m:
            pa[i]=m
        else:
            pa[i]=pa[i-1]+(int)(a[i]==b[pa[i-1]])
#   print pa[i]
ans="-"
length=0
pb=[0 for _ in xrange(n)]

# print "-------"

for i in range(n-1,-1,-1):
    if i==n-1:
        if pa[i]>length:
            length=pa[i]
            ans=b[:pa[i]]
    else:
        if length<m and pa[i]+pb[i+1]>length:
            length=pa[i]+pb[i+1]
            ans=b[:pa[i]]+b[-pb[i+1]:]
    if i==n-1:
        pb[i]=a[-1]==b[-1]
    else:
        if pb[i+1]==m:
            pb[i]=m
        else:
            pb[i]=pb[i+1]+(a[i]==b[-pb[i+1]-1])
if pb[0]>length:
    length=pb[0]
    ans=b[-pb[0]:]

print ans