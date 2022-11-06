#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

long long a[5010];
long long dp[5010][5010];

int main()
{
	int n, m, x; scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	memset(dp, -0x3f, sizeof(dp)); dp[0][0] = 0;
	for(int j = 1; j <= x; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int k = std::max(i - m, 0); k < i; k++)
			{
				dp[i][j] = std::max(dp[i][j], dp[k][j - 1] + a[i]);
			}
		}
	}
	long long ans = -1e18;
	for(int i = n - m + 1; i <= n; i++) ans = std::max(ans, dp[i][x]);
	if(ans >= 0) printf("%lld\n", ans);
	else puts("-1");
	return 0;
}