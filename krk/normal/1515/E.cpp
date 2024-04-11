#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 405;

int n, mod;
int C[Maxn][Maxn];
int all[Maxn];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &mod);
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			all[i] = (all[i] + C[i - 1][j - 1]) % mod;
	dp[1][1] = all[1];
	for (int i = 2; i <= n; i++) {
		dp[i][i] = all[i];
		for (int j = 2; j < i; j++)
			for (int k = 0; k <= i - j; k++)
				dp[i][j - 1 + k] = (dp[i][j - 1 + k] + ll(all[j - 1]) * dp[i - j][k] % mod * C[j - 1 + k][k]) % mod;
	}
	int res = 0;
	for (int k = 0; k <= n; k++)
		res = (res + dp[n][k]) % mod;
	printf("%d\n", res);
    return 0;
}