#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20005;
const int Maxk = 52;
const int Maxp = 105;
const int Inf = 1000000007;

int n, k, p;
int a[Maxn];
int cur, dp[2][Maxk][Maxp];

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	fill((int*)dp, (int*)dp + 2 * Maxk * Maxp, -Inf);
	dp[cur][0][a[0] % p] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < k; j++)
			for (int l = 0; l < p; l++) if (dp[cur][j][l] != -Inf) {
				int val = dp[cur][j][l]; dp[cur][j][l] = -Inf;
				int nl = (l + a[i]) % p;
				dp[!cur][j][nl] = max(dp[!cur][j][nl], val);
				nl = a[i] % p;
				dp[!cur][j + 1][nl] = max(dp[!cur][j + 1][nl], val + l);
			}
		cur = !cur;
	} 
	int res = -Inf;
	for (int l = 0; l < p; l++) if (dp[cur][k - 1][l] != -Inf)
		res = max(res, dp[cur][k - 1][l] + l);
	printf("%d\n", res);
	return 0;
}