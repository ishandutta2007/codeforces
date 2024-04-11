n = int(input())
a = list(map(int, input().split()))
dp = [0] * 4
for j in range(n):
	dp = [dp[i] if i == 0 else max(dp[i], dp[i - 1]) for i in range(4)]
	dp = [dp[i] + (1 if i % 2 == a[j] - 1 else 0) for i in range(4)]
print(max(dp))