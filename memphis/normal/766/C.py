import math

p=1000000007
n=int(raw_input())
s=raw_input()
readin=raw_input().split()
lim=[]
for i in readin:
    lim.append(int(i))

f=[0 for i in range(n)]
g=[0 for i in range(n)]
h=[0 for i in range(n)]

for i in range(0,n):
    k=n
    h[i]=i+1
    for j in range(i,-1,-1):
        k=min(k,lim[ord(s[j])-ord('a')])
        if k>=i-j+1:
            if j==0:
                f[i]=(f[i]+1)%p
                g[i]=max(g[i],i+1)
                h[i]=min(h[i],1)
            else:
                f[i]=(f[i]+f[j-1])%p
                g[i]=max(g[i],max(g[j-1],i-j+1))
                h[i]=min(h[i],h[j-1]+1)
        else:
            break

print f[n-1]
print g[n-1]
print h[n-1]