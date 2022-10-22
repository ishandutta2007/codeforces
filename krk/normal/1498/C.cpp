#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int mod = 1000000007;

int T;
int n, k;
int dp[Maxn][Maxn][2];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i <= k; i++)
			for (int j = 0; j < n; j++)
				for (int l = 0; l < 2; l++)
					dp[i][j][l] = 0;
		dp[k][0][0] = 1;
		int res = 1;
		for (int i = k; i > 0; i--) {
			for (int j = 0; j < n; j++) if (dp[i][j][0]) {
				if (j + 1 < n)
					dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i][j][0]) % mod;
				if (i > 1) {
					res = (res + dp[i][j][0]) % mod;
					if (j > 0)
						dp[i - 1][j - 1][1] = (dp[i - 1][j - 1][1] + dp[i][j][0]) % mod;
				}
			}
			for (int j = n - 1; j >= 0; j--) if (dp[i][j][1]) {
				if (j - 1 >= 0)
					dp[i][j - 1][1] = (dp[i][j - 1][1] + dp[i][j][1]) % mod;
				if (i > 1) {
					res = (res + dp[i][j][1]) % mod;
					if (j + 1 < n)
						dp[i - 1][j + 1][0] = (dp[i - 1][j + 1][0] + dp[i][j][1]) % mod;
				}
			}
		}
		printf("%d\n", res);
	}
    return 0;
}