t=int(input())
for _ in range(t):
    n,x,y=map(int,input().split())
    if y<x:
        x,y=y,x
    mi=0
    tot=max(n-x-2+1,0)
    tot2=max(n-y-2+1,0)
    mi+=min(tot,y-1)
    mi+=min(tot2,x-1)
    tot-=min(tot,y-1)
    tot2-=min(tot2,x-1)

    mi+=min(tot,tot2)
    if x<n and y<n:
        mi+=1



    ma=0
    tot=max(y-1,0)
    tot2=max(x-1,0)
    ma+=min(tot,n-x-1+1)
    ma+=min(tot2,n-y-1+1)
    tot-=min(tot,n-x-1+1)
    tot2-=min(tot2,n-y-1+1)

    ma+=min(tot,tot2)
    
    print(n-mi,ma+1)