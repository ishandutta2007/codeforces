t=int(input())
for _ in range(t):
    n,m,k=map(int,input().split())
    it=list(map(int,input().split()))
    dp=[0]*(n)
    dp[0]=m
    st=False
    for i in range(1,n):
        if it[i]>it[i-1]+k:
            dp[i]=dp[i-1]-(it[i]-it[i-1]-k)
        elif it[i]<it[i-1]-k:
            dp[i]=dp[i-1]+it[i-1]-it[i]
            dp[i]+=min(it[i],k)
        elif it[i-1]>=it[i]:
            dp[i]=dp[i-1]+it[i-1]-it[i]
            dp[i]+=min(k,it[i])
        elif it[i-1]<it[i]:
            dp[i]=dp[i-1]+min(k-(it[i]-it[i-1]),it[i-1])
        if dp[i]<0:
            st=True
            break
    if st:
        print("NO")
    else:
        print("YES")
   # print(dp)