inf = 10 ** 100

b = int(input())
s = input()
n = len(s)

dp = []
for i in range(n + 1):
    dp.append([inf] * (n + 2))
dp[n][0] = 0   
for i in range(n - 1, -1, -1):
    for j in range(i + 1, min(i + 12, n + 1)):
        if j - i > 1 and s[i] == '0':
            continue
        cur = int(s[i:j])
        if cur >= b:
            continue
        for p in range(n + 1):
            dp[i][p + 1] = min(dp[i][p + 1], dp[j][p] + cur)
            cur *= b
res = inf
for p in range(n + 2):  
    res = min(res, dp[0][p])
print(res)