#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 505;

int n, m, b, mod;
int a[Maxn];
int dp[2][Maxn][Maxn];
int cur;
int res;

int main()
{
	scanf("%d %d %d %d", &n, &m, &b, &mod);
	dp[cur][0][0] = 1 % mod;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		fill((int*)dp[!cur], (int*)dp[!cur] + Maxn * Maxn, 0);
		for (int j = 0; j <= m; j++)
			for (int l = 0; l <= b; l++) {
				dp[!cur][j][l] = (dp[!cur][j][l] + dp[cur][j][l]) % mod;
				if (j + 1 <= m && l + a[i] <= b)
					dp[cur][j + 1][l + a[i]] = (dp[cur][j + 1][l + a[i]] + dp[cur][j][l]) % mod;
			}
		cur = !cur;
	}
	for (int l = 0; l <= b; l++)
		res = (res + dp[cur][m][l]) % mod;
	printf("%d\n", res);
	return 0;
}