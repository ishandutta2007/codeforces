#include <stdio.h>
#define MAXN 2005
#define MOD 1000000007

int dp[MAXN][MAXN], n, len;

int init()
{
	scanf("%d%d", &n, &len);
	return 0;
}
int solve()
{
	int i, j, k, ans = 0;
	for(i = 0; i <= n; i ++)
		dp[1][i] = 1;
	for(i = 2; i <= len; i ++)
		for(j = 1; j <= n; j ++)
			for(k = j; k <= n; k += j)
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
	for(i = 1; i <= n; i ++)
		ans = (ans + dp[len][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}