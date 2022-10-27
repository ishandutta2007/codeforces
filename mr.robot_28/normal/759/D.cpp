#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 2e5;
const int mod = 1e9 + 7;

signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> comps;
	for(int i = 0; i < sz(s); i++)
	{
		int c = s[i] - 'a';
		if(sz(comps) == 0 || comps.back() != c)
		{
			comps.push_back(c);
		}
	}
	int m = sz(comps);
	vector <vector <int> > dp(m + 1, vector <int> (27, 0));
	dp[0][26] = 1;
	vector <int> sum(m + 1);
	sum[0] = 1;
	for(int i = 0; i < sz(comps); i++)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			sum[j + 1] = (sum[j + 1] - dp[j + 1][comps[i]] + mod) % mod;
			dp[j + 1][comps[i]] = (sum[j] - dp[j][comps[i]] + mod) % mod;
			sum[j + 1] = (sum[j + 1] + dp[j + 1][comps[i]]) % mod;
		}
	}
	vector <int> dp1(m + 1);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			dp1[i] = (dp1[i] + dp[i][j]) % mod;
		}
	}
	int cnk[n + 1][n + 1];
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++){
			cnk[i][j] = 0;
		}
	}
	cnk[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		cnk[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
	{
	//	cout << cnk[]
		ans = (ans + 1LL * dp1[i] * cnk[n - 1][i -1 ]) % mod;
	}
	cout << ans;
	return 0;
}