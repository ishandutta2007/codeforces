#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int mod = 1000000007;
const int Maxd = 10;

int C[Maxn][Maxn];
int n;
int tims[Maxd];
int dp[Maxd + 1][Maxn];
int res;

int getSum(int d)
{
	int res = 0;
	for (int i = 0; i < Maxd; i++)
		res += max(0, tims[i] - (d == i));
	return res;
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d", &n);
	for (int i = 0; i < Maxd; i++)
		scanf("%d", &tims[i]);
	int sum = getSum(-1);
	if (sum == 0) res = 9;
	else if (sum == 1) res = 1;
	for (int i = 2; i <= n; i++)
		for (int d = 1; d < Maxd; d++) {
			sum = getSum(d);
			if (sum > i - 1) continue;
			fill((int*)dp, (int*)dp + (Maxd + 1) * Maxn, 0); dp[0][1] = 1;
			for (int l = 0; l < Maxd; l++) {
				int has = max(0, tims[l] - (d == l));
				for (int j = 0; j <= i; j++)
					for (int k = has; j + k <= i; k++) {
						dp[l + 1][j + k] += ll(dp[l][j]) * ll(C[i - j][k]) % ll(mod);
						dp[l + 1][j + k] %= mod;
					}
			}
			res = (res + dp[Maxd][i]) % mod;
		}
	printf("%d\n", res);
	return 0;
}