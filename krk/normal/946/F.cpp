#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int mod = 1000000007;

int n, x;
string s;
int pw[Maxn];
int dp[Maxn][Maxn][Maxn][2][2];

int main()
{
	cin >> n >> x;
	cin >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == '0') dp[0][i][i][1][1] = 1;
		else dp[1][i][i][1][1] = 1;
	pw[0] = 2; pw[1] = 2;
	for (int i = 2; i <= x; i++) {
		int a = i - 1, b = i - 2;
		pw[i] = ll(pw[a]) * pw[b] % mod;
		for (int l = 0; l < n; l++)
			for (int r = l; r < n; r++)
				for (int fl = 0; fl < 2; fl++)
					for (int fr = 0; fr < 2; fr++) {
						dp[i][l][r][fl][fr] = (dp[i][l][r][fl][fr] + ll(dp[a][l][r][fl][fr])) % mod;
						dp[i][l][r][fl][0] = (dp[i][l][r][fl][0] + ll(dp[a][l][r][fl][fr]) * (pw[b] - 1)) % mod;
						dp[i][l][r][fl][fr] = (dp[i][l][r][fl][fr] + ll(dp[b][l][r][fl][fr])) % mod;
						dp[i][l][r][0][fr] = (dp[i][l][r][0][fr] + ll(dp[b][l][r][fl][fr]) * (pw[a] - 1)) % mod;
						for (int m = l; m < r; m++)
							dp[i][l][r][fl][fr] = (dp[i][l][r][fl][fr] + ll(dp[a][l][m][fl][1]) * dp[b][m + 1][r][1][fr]) % mod;
					}
	}
	int res = 0;
	for (int fl = 0; fl < 2; fl++)
		for (int fr = 0; fr < 2; fr++)
			res = (res + dp[x][0][n - 1][fl][fr]) % mod;
	printf("%d\n", res);
	return 0;
}