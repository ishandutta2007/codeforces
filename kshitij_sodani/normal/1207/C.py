t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    s=input()
    dp=[[float("inf")]*2 for i in range(n+1)]
    dp[0][0]=b
    for i in range(1,n+1):
        if s[i-1]=="0":
            dp[i][0]=min(dp[i-1][0]+a+b,dp[i-1][1]+2*a+b)
            dp[i][1]=min(dp[i-1][1]+2*b+a,dp[i-1][0]+2*b+2*a)
        else:
            dp[i][1]=dp[i-1][1]+2*b+a
    print(dp[-1][0])