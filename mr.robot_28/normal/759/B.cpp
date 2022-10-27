#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;

signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	vector <int> t(n);
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	vector <int> dp(n);
	dp[0] = 20;
	cout << 20 << "\n";
	vector <int> vals = {1, 90, 1440};
	vector <int> vals1 = {20, 50, 120};
	for(int i = 1; i < n; i++)
	{
		dp[i] = 1e9;
		for(int j = 0; j < 3; j++)
		{
			int uk = lower_bound(t.begin(), t.end(), t[i] - vals[j] + 1) - t.begin();
			uk--;
			int val = 0;
			if(uk != -1)
			{
				val = dp[uk];
			}
			dp[i] = min(dp[i], val + vals1[j]);
		}
		cout << dp[i] - dp[i - 1] << "\n";
	}
	return 0;
}