#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 30005;
const int Maxk = 205;
const int Inf = 1000000000;

int n, k;
int a[Maxn];
int dp[Maxn][Maxk][2];
int res = -Inf;

int Add(int val, int sgn) { return sgn == 0? -val: val; }

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			dp[i][j][0] = dp[i][j][1] = -Inf;

	for (int i = n - 1; i >= 0; i--) {
		for (int l = 0; l < 2; l++) {
			int sum = 0;
			for (int z = i; z < n; z++) {
				sum += Add(a[z], l);
				dp[i][1][l] = max(dp[i][1][l], sum);
			}
		}
		for (int j = k; j >= 0; j--)
			for (int l = 0; l < 2; l++) {

				dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j][l]);

				if (j > 0) {
					dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l]);

					int sum = 0;
					for (int z = i; z < n; z++) {
						sum += Add(a[z], l);
						dp[i][j][l] = max(dp[i][j][l], dp[z + 1][j - 1][1 - l] + 2 * sum);
					}
				}
			}
	}

	for (int i = 0; i < n; i++)
		for (int l = 0; l < 2; l++) {
			int sum = 0;
			for (int z = i; z < n; z++) {
				sum += Add(a[z], l);
				res = max(res, sum + dp[z + 1][k - 1][1 - l]);
			}
		}

	printf("%d\n", res);
	return 0;
}