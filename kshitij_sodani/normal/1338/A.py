t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    mi=it[0]
    ans=0
    for i in range(1,n):
        if it[i]<mi:
            ans=max(ans,len(bin(mi-it[i]))-2)
        mi=max(mi,it[i])
    print(ans)