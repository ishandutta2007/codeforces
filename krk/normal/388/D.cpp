#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxb = 32;

int k;
int dp[Maxb][Maxb][2];
int res;

int main()
{
	scanf("%d", &k);
	dp[Maxb - 1][0][0] = 1;
	for (int i = Maxb - 1; i >= 1; i--) {
		int b = i - 1;
		for (int j = 0; j < Maxb; j++)
			for (int l = 0; l < 2; l++) if (dp[i][j][l]) {
				// take new
				if (l || (k & 1 << b)) dp[i - 1][j + 1][l] = (dp[i - 1][j + 1][l] + dp[i][j][l]) % mod;
				// has nothing - take nothing
				if (j == 0) dp[i - 1][j][l || (k & 1 << b)] = (dp[i - 1][j][l || (k & 1 << b)] + dp[i][j][l]) % mod;
				else {
					// take nils
					dp[i - 1][j][l || (k & 1 << b)] = (dp[i - 1][j][l || (k & 1 << b)] + ll(dp[i][j][l]) * (1 << j - 1) % mod) % mod;
					// take ones
					if (l || (k & 1 << b)) dp[i - 1][j][l] = (dp[i - 1][j][l] + ll(dp[i][j][l]) * (1 << j - 1) % mod) % mod;
				}
			}
	}
	for (int j = 0; j < Maxb; j++)
		for (int l = 0; l < 2; l++)
			res = (res + dp[0][j][l]) % mod;
	printf("%d\n", res);
	return 0;
}