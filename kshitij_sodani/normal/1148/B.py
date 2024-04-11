import bisect as bs
n,m,ta,tb,k=map(int,input().split())
it=list(map(int,input().split()))
it2=list(map(int,input().split()))
ind=0
can_b=0
st=False
ma=0
if k>=n or k>=m:
    print(-1)
else:
    for i in range(k+1):
        x=it[i]+ta
        xx=bs.bisect_left(it2,x)
        xx+=(k-i)
        if xx>=m:
            ma=-1
            break
        ans=it2[xx]+tb
        if ans>ma:
            ma=ans
    print(ma)