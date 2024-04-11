n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(a[0])
    exit()
inf = 1002003004005006007
dp = [[[-inf, -inf, -inf] for _ in range(2)] for _ in range(n + 1)]
dp[0][0][0] = 0
for i in range(n):
    for j in range(2):
        for k in range(3):
            dp[i+1][j][(k+1)%3] = max(dp[i+1][j][(k+1)%3], dp[i][j][k] + a[i])
            dp[i+1][j][(k-1)%3] = max(dp[i+1][j][(k-1)%3], dp[i][j][k] - a[i])
    if i + 1 < n:
        for k in range(3):
            dp[i+2][1][(k+2)%3] = max(dp[i+2][1][(k+2)%3], dp[i][0][k] + a[i] + a[i+1])
            dp[i+2][1][(k-2)%3] = max(dp[i+2][1][(k-2)%3], dp[i][0][k] - a[i] - a[i+1])
ans = dp[n][1][1]
print(ans)