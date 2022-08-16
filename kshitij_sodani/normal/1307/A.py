t=int(input())
for _ in range(t):
    n,d=map(int,input().split())
    it=list(map(int,input().split()))
    tot=d
    ans=it[0]
    for i in range(1,n):
        if it[i]*i<=tot:
            tot-=it[i]*i
            ans+=it[i]
        else:
            ans+=tot//i
            break
        
    print(ans)