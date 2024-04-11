#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <pair <int, int> > dp(n + 1);
	dp[0] = {0, 1};
	vector <int> cnt(26);
	for(int i = 0; i < n; i++)
	{
		cnt[s[i] - 'A']++;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(dp[i].first + cnt[j] > dp[i + 1].first)
			{
				dp[i + 1].first = dp[i].first + cnt[j];
				dp[i + 1].second = dp[i].second;
			}
			else if(dp[i + 1].first == dp[i].first + cnt[j])
			{
				dp[i + 1].second += dp[i].second;
				if(dp[i + 1].second >= mod)
				{
					dp[i + 1].second -= mod;
				}
			}
		}
	}
	cout << dp[n].second;
    return 0;
}