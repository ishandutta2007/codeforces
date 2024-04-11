def check(mid):
    return n-(mid*(mid+1))//2<=m
n,m=map(int,input().split())
low=1
high=10**36
tot=max(m*(m-1)//2,n)

while low<high and high-low>=3:
    mid=(low+high)//2
    st=check(mid)

    if st:
        high=mid
    else:
        low=mid
ans=high+1
for i in range(low,high+1):
    st=check(i)
    
    if st:
        ans=min(ans,i)
if m<n:
    print(ans+m)
else:
    print(n)