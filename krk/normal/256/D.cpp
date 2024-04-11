#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 260;
const int Maxm = 25;
const int mod = 777777777;

int C[Maxn][Maxn];
int n, k;
int dp[Maxm][Maxn][Maxn][2];
int res;

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d %d", &n, &k);
	dp[0][n - k][k][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int c = Maxm - 2; c >= 0; c--)
			for (int a = 0; a <= n - k; a++) {
			    if (a != 0 && a < i) a = i;
				for (int b = i <= a? 0: i; b <= k; b++)
					for (int l = 0; l < 2; l++) if (dp[c][a][b][l]) {
						if (i <= a)
							dp[c + 1][a - i][b][l] = (dp[c + 1][a - i][b][l] + ll(C[a + b][i]) * dp[c][a][b][l]) % mod;
						if (i <= b)
							dp[c + 1][a][b - i][1 - l] = (dp[c + 1][a][b - i][1 - l] + ll(C[a + b][i]) * dp[c][a][b][l]) % mod;
					}
			}
	for (int c = 0; c < Maxm; c++)
		for (int b = 0; b <= k; b++)
			for (int l = 0; l < 2; l++) {
				int add = dp[c][0][b][l];
				for (int z = 0; z < b; z++)
					add = ll(add) * (n - c) % mod;
				if (l == 0) res = (res + add) % mod;
				else res = (res - add + mod) % mod;
			}
	printf("%d\n", res);
    return 0;
}