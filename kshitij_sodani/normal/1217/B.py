t=int(input())
for _ in range(t):
    n,xx=map(int,input().split())
    #print(n,xx)
    it=[]
    for __ in range(n):
        it.append(list(map(int,input().split())))
    x=max(it,key=lambda a:a[0]-a[1])
    r=x[0]-x[1]
    
    if r<=0:
        if max(it)[0]>=xx:
            print(1)
        else:
            print(-1)
        continue
    aa=max(it)[0]
    xx=max(0,xx-aa)
    
    tot=(xx/r)
    if tot%1!=0:
        tot=int(tot)+1
    else:
        tot=int(tot)
    print(tot+1)