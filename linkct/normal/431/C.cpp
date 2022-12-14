#include <stdio.h>
#define MAXN 105
#define MOD 1000000007

int dp[MAXN][MAXN][2], n, k, d;

int main()
{
	int i, j, l, ans = 0;
	scanf("%d%d%d", &n, &k, &d);
	for(i = 1; i < d; i ++)
		dp[1][i][0] = 1;
	for(; i <= k; i ++)
		dp[1][i][1] = 1;
	for(i = 2; i <= n; i ++)
		for(j = 1; j <= n; j ++)
			for(l = 1; l <= k; l ++)
				if(j >= l)
					if(l >= d)
					{
						dp[i][j][1] += dp[i - 1][j - l][0];
						dp[i][j][1] %= MOD;
						dp[i][j][1] += dp[i - 1][j - l][1];
						dp[i][j][1] %= MOD;
					}
					else
					{
						dp[i][j][1] += dp[i - 1][j - l][1];
						dp[i][j][1] %= MOD;
						dp[i][j][0] += dp[i - 1][j - l][0];
						dp[i][j][0] %= MOD;
					}
	for(i = 1; i <= n; i ++)
	{
		ans += dp[i][n][1];
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}