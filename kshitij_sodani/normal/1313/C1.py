import sys
input=sys.stdin.readline
n=int(input())
ma=0
ans=[0 for i in range(n)]
it=list(map(int,input().split()))
for i in range(1,n):
    tot=0
    mi=0
    suff=[0 for i in range(n)]
    suff[i]=it[i]

    for j in range(i-1,-1,-1):
        suff[j]=it[j]
        if suff[j+1]<suff[j]:
            suff[j]=suff[j+1]
    for k in range(i+1,n):
        if it[k]<=suff[k-1]:
            suff[k]=it[k]
        else:
            suff[k]=suff[k-1]
    x=sum(suff)
    if x>=ma:
        ans=suff
        ma=x
suff=[0 for i in range(n)]
suff[0]=it[0]
for i in range(1,n):
    suff[i]=min(it[i],suff[i-1])
if sum(suff)>ma:
    ans=suff
print(*ans)