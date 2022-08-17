n, K = map(int, input().split())
s = input()
max_n = 104
dp = [[0] * max_n for i in range(max_n)] 
s = "$" + s;
for i in range(n + 1):
  dp[0][i] = 1;

for ln in range(1, n + 1):
  for j in range(1, n + 1):
    dp[ln][j] = dp[ln][j - 1] + dp[ln - 1][j - 1];
    for k in range(j - 1, 0, -1):
      if s[k] == s[j]:
        dp[ln][j] -= dp[ln - 1][k - 1];
        break;
ans = 0;
for ln in range(n, -1, -1):
  cnt = dp[ln][n];
  if (cnt < K):
    ans += (cnt * (n - ln));
    K -= cnt;
  else:
    ans += (K * (n - ln));
    K = 0;
    break;
if (K != 0):
  print(-1)
else:
  print(ans)