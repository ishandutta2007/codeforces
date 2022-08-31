n=int(input())
it=list(map(int,input().split()))
dp=[1 for i in range(n)]
for i in range(1,n):
    if it[i]>it[i-1]:
        dp[i]=dp[i-1]+1
do=[1 for i in range(n)]
for i in range(n-2,-1,-1):
    if it[i]<it[i+1]:
        do[i]=do[i+1]+1
ma=max(dp)
for i in range(1,n-1):
    if it[i+1]>it[i-1]:
        ma=max(ma,do[i+1]+dp[i-1])
print(ma)