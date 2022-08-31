t=int(input())
for _ in range(t):
    n,k,d=map(int,input().split())
    
    it=list(map(int,input().split()))
    it=[i-1 for i in it]
    x=it[:d]
    ss=[0]*k
    tot=0
    for i in x:
        
        ss[i]+=1
        if ss[i]==1:
            tot+=1
    ma=tot
    for i in range(n-d):
        ss[it[i]]-=1
        if ss[it[i]]==0:
            tot-=1
        ss[it[i+d]]+=1
        if ss[it[i+d]]==1:
            tot+=1
        ma=min(ma,tot)
    print(ma)