#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Inf = 1000000000;

int T;
int n, x;
int a[Maxn];
int dp[2][Maxn][Maxn];
int cur;

int main()
{
	fill((int*)dp, (int*)dp + 2 * Maxn * Maxn, Inf);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &x);
		dp[cur][0][x] = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			for (int j = 0; j < Maxn; j++)
				for (int l = 0; l < Maxn; l++) if (dp[cur][j][l] < Inf) {
					if (j <= a) dp[!cur][a][l] = min(dp[!cur][a][l], dp[cur][j][l]);
					if (j <= l && l < a) dp[!cur][l][a] = min(dp[!cur][l][a], dp[cur][j][l] + 1);
					dp[cur][j][l] = Inf;
				}
			cur = !cur;
		}
		int res = Inf;
		for (int j = 0; j < Maxn; j++)
			for (int l = 0; l < Maxn; l++) if (dp[cur][j][l] < Inf) {
				res = min(res, dp[cur][j][l]);
				dp[cur][j][l] = Inf;
			}
		printf("%d\n", res < Inf? res: -1);
	}
    return 0;
}