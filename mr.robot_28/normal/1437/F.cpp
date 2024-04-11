#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i= 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector <int> cnt(n), last(n);
	for(int i = 0; i < n; i++)
	{
		cnt[i] = 0;
		last[i] = -1;
		for(int j = 0; j < n; j++)
		{
			if(a[j] * 2 <= a[i])
			{
				cnt[i]++;
				last[i] = j;
			}
		}
	}
	vector <vector <int> > dp(n, vector <int> (n + 1, 0)), pref(n + 1, vector <int>(n + 1, 0));
	for(int i = 0; i < n; i++)
	{
		dp[i][1] = 1;
		pref[i + 1][1] = pref[i][1] + dp[i][1];
		if(pref[i + 1][1] >= mod)
		{
			pref[i + 1][1] -= mod;
		}
	}
	for(int k = 2; k <= n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			if(cnt[i] + 1 >= k)
			{
				dp[i][k] = dp[i][k - 1] * (cnt[i]  + 2 - k + mod) % mod + pref[last[i] + 1][k - 1];
				if(dp[i][k] >= mod)
				{
					dp[i][k] -= mod;
				}
			}
			else
			{
				dp[i][k] = 0;
			}
			pref[i + 1][k] = pref[i][k] + dp[i][k];
			if(pref[i + 1][k] >= mod)
			{
				pref[i + 1][k] -= mod;
			}
		}
	}
	cout << dp[n - 1][n];
	return 0;
}