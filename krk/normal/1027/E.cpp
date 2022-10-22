#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int mod = 998244353;

int n, k;
int cur, dp[2][Maxn];
int ways[Maxn];
int solve[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int a = 1; a <= n; a++) {
		dp[cur][1] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= a && j <= i; j++) if (dp[cur][j]) {
				int my = dp[cur][j]; dp[cur][j] = 0;
				if (j + 1 <= a) dp[!cur][j + 1] = (dp[!cur][j + 1] + my) % mod;
				dp[!cur][1] = (dp[!cur][1] + my) % mod;
			}
			cur = !cur;
		}
		for (int j = 0; j <= a; j++) {
			ways[a] = (ways[a] + dp[cur][j]) % mod;
			dp[cur][j] = 0;
		}
	}
	solve[0][n] = 2;
	for (int i = 0; i < n; i++)
		for (int a = 0; a <= n; a++) if (solve[i][a])
			for (int j = i + 1; j <= n; j++) {
				int len = j - i;
				int na = min(a, (k - 1) / len);
				solve[j][na] = (solve[j][na] + ll(solve[i][a])) % mod;
			}
	int res = 0;
	for (int a = 0; a <= n; a++)
		res = (res + ll(solve[n][a]) * ways[a]) % mod;
	printf("%d\n", res);
	return 0;
}