#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 105;

int T;
int n, m;
ll B[Maxn][Maxn];
ll dp[2][Maxn][Maxn][Maxn];
int cur;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%I64d", &B[i][j]);
				B[i][j] -= (i + j);
			}
		for (int j = 0; j < m; j++)
			for (int a = 0; a < n; a++)
				for (int b = 0; b < m; b++)
					dp[cur][j][a][b] = Inf;
		dp[cur][0][0][0] = B[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				for (int a = 0; a < n; a++)
					for (int b = 0; b < m; b++)
						dp[!cur][j][a][b] = Inf;
			for (int j = 0; j < m; j++)
				for (int a = 0; a <= i; a++)
					for (int b = 0; b <= j; b++) if (dp[cur][j][a][b] < Inf) {
						if (i + 1 < n)
							if (B[i + 1][j] < B[a][b])
								dp[!cur][j][i + 1][j] = min(dp[!cur][j][i + 1][j], dp[cur][j][a][b] + B[i + 1][j]);
							else dp[!cur][j][a][b] = min(dp[!cur][j][a][b], dp[cur][j][a][b] + B[i + 1][j]);
						if (j + 1 < m)
							if (B[i][j + 1] < B[a][b])
								dp[cur][j + 1][i][j + 1] = min(dp[cur][j + 1][i][j + 1], dp[cur][j][a][b] + B[i][j + 1]);
							else dp[cur][j + 1][a][b] = min(dp[cur][j + 1][a][b], dp[cur][j][a][b] + B[i][j + 1]);
					}
			cur = !cur;
		}
		ll res = Inf;
		for (int a = 0; a < n; a++)
			for (int b = 0; b < m; b++) if (dp[!cur][m - 1][a][b] < Inf)
				res = min(res, dp[!cur][m - 1][a][b] - ll(n + m - 1) * B[a][b]);
		printf("%I64d\n", res);
	}
    return 0;
}