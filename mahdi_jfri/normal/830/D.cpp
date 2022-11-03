#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e2 + 20;
const int mod = 1e9 + 7;

int dp[maxn][maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[1][1] = 1;
	dp[1][0] = 1;

	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = 1;
		for(int j = 1; j <= n; j++)
		{
			int tmp = 0;
			for(int k = 0; k <= j + 1; k++)
				mkay(tmp += 1LL * dp[i - 1][k] * dp[i - 1][j - k + 1] % mod);

			tmp = 1LL * tmp * (j + 1) % mod * j % mod;
			mkay(dp[i][j] += tmp);

			for(int k = 0; k <= j - 1; k++)
				mkay(dp[i][j] += 1LL * dp[i - 1][k] * dp[i - 1][j - k - 1] % mod);

			tmp = 0;
			for(int k = 0; k <= j; k++)
				mkay(tmp += 1LL * dp[i - 1][k] * dp[i - 1][j - k] % mod);

			mkay(dp[i][j] += 2LL * tmp * j % mod);
			mkay(dp[i][j] += tmp);
		}
	}

	cout << dp[n][1] << endl;
}