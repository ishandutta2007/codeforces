#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int mod = 1e9 + 7;

int dp[maxn][maxn][2];

// 0 : nadashte bashe
// 1 : mitune dashte bashe

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	int n , k;
	string s;
	cin >> n >> k >> s;
	dp[n][0][0] = dp[n][0][1] = 1;
	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j <= k; j++)
		{
			ok(dp[i][j][0] = (1LL * dp[i + 1][j][1] * (s[i] - 'a') % mod) + dp[i + 1][j][0]);
			dp[i][j][1] = dp[i][j][0];
			bool f = 0;
			for(int pt = i; pt < n && !f; pt++)
			{
				int x = (pt - i + 1) * (n - pt);
				if(x > j)
					f = 1;
				else
					ok(dp[i][j][1] += 1LL * dp[pt + 1][j - x][1] * ('z' - s[pt]) % mod);
			}
			for(int pt = n - 1; pt >= i && f; pt--)
			{
				int x = (pt - i + 1) * (n - pt);
				if(x > j)
					f = 0;
				else
					ok(dp[i][j][1] += 1LL * dp[pt + 1][j - x][1] * ('z' - s[pt]) % mod);
			}
		}
	cout << dp[0][k][1] << endl;
}