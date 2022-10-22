#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 101;
const int Maxm = 305;

int n, T;
int a[Maxn];
int freq[Maxm];
int dp[Maxn][Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		freq[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
		dp[1][i][freq[a[i]]] = 1;
	for (int i = 1; i < Maxn; i++)
		for (int j = 1; j <= n; j++)
			for (int z = 0; z <= n; z++) if (dp[i][j][z]) {
				if (i + 1 < Maxn)
					for (int l = 1; l <= j; l++) if (a[j] <= a[l]) {
						int nz = max(z, freq[a[l]]);
						dp[i + 1][l][nz] = max(dp[i + 1][l][nz], dp[i][j][z] + 1);
					}
				for (int l = j + 1; l <= n; l++) if (a[j] <= a[l]) {
					int nz = max(z, freq[a[l]]);
					dp[i][l][nz] = max(dp[i][l][nz], dp[i][j][z] + 1);
				}
			}
	for (int i = 1; i < Maxn && i <= T; i++)
		for (int j = 1; j <= n; j++)
			for (int z = 0; z <= n; z++) if (dp[i][j][z])
				res = max(res, dp[i][j][z] + (T - i) * z);
	printf("%d\n", res);
	return 0;
}