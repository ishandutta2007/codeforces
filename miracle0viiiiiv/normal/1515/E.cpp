#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, MOD, dp[405][405];

int main()
{
	cin >> n >> MOD;
	dp[0][0] = 1;
	rep(i, n) for(int j = 0; j <= i; j ++) {
		dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 1LL * (j + 1) * dp[i][j]) % MOD;
		dp[i + 1][j] = (dp[i + 1][j] + 2LL * j * dp[i][j]) % MOD;
		dp[i + 2][j] = (dp[i + 2][j] + 2LL * j * dp[i][j]) % MOD;
		dp[i + 2][j - 1] = (dp[i + 2][j - 1] + 2LL * (j - 1) * dp[i][j]) % MOD;
		dp[i + 3][j - 1] = (dp[i + 3][j - 1] + 1LL * (j - 1) * dp[i][j]) % MOD;
	}
	
	cout << dp[n][1] << endl;
	return 0;
}