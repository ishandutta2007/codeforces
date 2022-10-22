#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 505;
const int mod = 1000000007;

int n, m;
char B[Maxn][Maxn];
int dp[2][Maxn][Maxn], cur;
int tot;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	tot = n + m - 2;
	dp[cur][0][n - 1] = B[0][0] == B[n - 1][m - 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				dp[!cur][j][k] = 0;
		for (int j = 0; j < m; j++)
			if (i + j < tot / 2) {
				for (int k = 0; k < n; k++) if (dp[cur][j][k]) {
					int l = tot - k - i - j;
					if (i + 1 < n && k - 1 >= 0 && B[i + 1][j] == B[k - 1][l])
						dp[!cur][j][k - 1] = (dp[!cur][j][k - 1] + dp[cur][j][k]) % mod;
					if (i + 1 < n && l - 1 >= 0 && B[i + 1][j] == B[k][l - 1])
						dp[!cur][j][k] = (dp[!cur][j][k] + dp[cur][j][k]) % mod;
					if (j + 1 < m && k - 1 >= 0 && B[i][j + 1] == B[k - 1][l])
						dp[cur][j + 1][k - 1] = (dp[cur][j + 1][k - 1] + dp[cur][j][k]) % mod;
					if (j + 1 < m && l - 1 >= 0 && B[i][j + 1] == B[k][l - 1])
						dp[cur][j + 1][k] = (dp[cur][j + 1][k] + dp[cur][j][k]) % mod;
				}
			} else if (i + j == tot / 2)
					for (int k = 0; k < n; k++) if (dp[cur][j][k]) {
						int l = tot - k - i - j;
						if (abs(i - k) + abs(j - l) <= 1 && B[i][j] == B[k][l])
							res = (res + dp[cur][j][k]) % mod;
					}
		cur = !cur;
	}
	printf("%d\n", res);
	return 0;
}