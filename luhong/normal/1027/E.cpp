#include <cstdio>
#define mod 998244353
 
int dp[2][510][510];

void rw(int &a, int b){a = (a + b) % mod;}
int Max(int a, int b){return a > b ? a : b ;}
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	dp[1][1][1] = 2;
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= i; j++)
			for(int k = 1; k <= j; k++)
				dp[(i & 1) ^ 1][j][k] = 0;
		for(int j = 1; j <= i; j++)
			for(int k = 1; k <= j; k++)
			{
				int ok = i & 1;
				rw(dp[ok ^ 1][Max(j, k + 1)][k + 1], dp[ok][j][k]);
				rw(dp[ok ^ 1][j][1], dp[ok][j][k]);
			}
	}
		
	int ans = 0;
	for(int j = 1; j <= n; j++)
		for(int k = 1; k <= n; k++) rw(dp[n & 1][j][0], dp[n & 1][j][k]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; i * j < k && j <= n; j++)
			rw(ans,1ll * dp[n & 1][i][0] * dp[n & 1][j][0] % mod);
	ans = 1ll * ans * ( mod + 1 >> 1 ) % mod;
	printf("%d\n", ans);
	return 0;
}