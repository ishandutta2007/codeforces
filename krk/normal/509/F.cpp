#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int mod = 1000000007;

int n;
int b[Maxn];
int dp[Maxn][Maxn][2];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = n - 1; i >= 0; i--) {
		dp[i][i][0] = 1;
		for (int j = i + 1; j < n; j++)
			dp[i][j][0] = dp[i + 1][j][1];
		for (int j = i; j < n; j++) {
			dp[i][j][1] = dp[i][j][0];
			for (int k = i; k < j; k++) if (b[i] < b[k + 1])
				dp[i][j][1] = (dp[i][j][1] + ll(dp[i][k][0]) * dp[k + 1][j][1]) % mod;
		}
	}
	printf("%d\n", dp[0][n - 1][0]);
	return 0;
}