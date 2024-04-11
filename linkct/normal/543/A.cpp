#include <cstdio>
#include <cstring>
const int MAXN = 505;

int n, m, b, mod, dp[2][MAXN][MAXN], a[MAXN];

int main(){
	int i, j, k, ans = 0;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	dp[0][0][0] = 1;
	for(i = 1; i <= n; ++ i){
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		for(j = 0; j <= m; ++ j)
			for(k = 0; k <= b; ++ k)
				if(j && k >= a[i]) dp[i & 1][j][k] = (dp[(i & 1) ^ 1][j][k] + dp[i & 1][j - 1][k - a[i]]) % mod;
				else dp[i & 1][j][k] = dp[(i & 1) ^ 1][j][k];
	}
	for(i = 0; i <= b; ++ i)
		ans += dp[n & 1][m][i], ans %= mod;
	printf("%d\n", ans);
	return 0;
}