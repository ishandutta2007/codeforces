#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 105;
const int Maxm = 110005;
const int nil = 10001;

int n, k;
int a[Maxn], b[Maxn];
int dp[Maxn][Maxm];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	fill((int*)dp, (int*)dp + Maxn * Maxm, -Inf);
	dp[0][nil] = 0;
	for (int i = 0; i < n; i++) {
		int ch = k * b[i] - a[i];
		for (int j = 0; j < Maxm; j++) if (dp[i][j] != -Inf) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + ch] = max(dp[i + 1][j + ch], dp[i][j] + a[i]);
		}
	}
	printf("%d\n", dp[n][nil] == 0? -1: dp[n][nil]);
	return 0;
}