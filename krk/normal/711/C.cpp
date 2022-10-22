#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const ll Inf = 1000000000000000000ll;

int n, m, k;
int c[Maxn];
int p[Maxn][Maxn];
ll dp[Maxn][Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &p[i][j]);
	fill((ll*)dp, (ll*)dp + Maxn * Maxn * Maxn, Inf);
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++)
			for (int l = 0; l <= k; l++) if (dp[i][j][l] != Inf)
				if (c[i] != 0) {
					int nl = l + (j != c[i]);
					dp[i + 1][c[i]][nl] = min(dp[i + 1][c[i]][nl], dp[i][j][l]);
				} else for (int z = 1; z <= m; z++) {
					int nl = l + (j != z);
					dp[i + 1][z][nl] = min(dp[i + 1][z][nl], dp[i][j][l] + p[i][z]);
				}
	ll res = Inf;
	for (int j = 1; j <= m; j++)
		res = min(res, dp[n][j][k]);
	if (res == Inf) printf("-1\n");
	else printf("%I64d\n", res);
	return 0;
}