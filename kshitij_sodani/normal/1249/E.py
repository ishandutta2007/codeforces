n,c=map(int,input().split())
aa=list(map(int,input().split()))
bb=list(map(int,input().split()))
dp=[[0,c] for i in range(n)]
for i in range(1,n):
    dp[i][0]=min(dp[i-1][0]+aa[i-1],dp[i-1][1]+aa[i-1])
    dp[i][1]=min(dp[i-1][0]+c+bb[i-1],dp[i-1][1]+bb[i-1])
print(*[min(i) for i in dp])