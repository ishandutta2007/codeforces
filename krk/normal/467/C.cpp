#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int n, m, k;
ll sum[Maxn];
ll dp[Maxn][Maxn];

ll Get(int ind) { return sum[ind] - sum[ind + m]; }

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &sum[i]);
	for (int i = n - 1; i >= 0; i--)
		sum[i] += sum[i + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (i + m <= n && j + 1 <= k) {
				int ni = min(i + m, n);
				dp[ni][j + 1] = max(dp[ni][j + 1], dp[i][j] + Get(i));
			}
		}
	printf("%I64d\n", dp[n][k]);
	return 0;
}