#include <bits/stdc++.h>
using namespace std;


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector <vector <int> > dp(n + 1, vector <int> (2 * n + 1, 1e9));
		dp[0][0] = 0;
		for(int i = 0; i < n; i++)
		{
			int t = 1e9;
			for(int j = 0; j <= n * 2 - 1; j++)
			{
				t = min(t, dp[i][j]);
				dp[i + 1][j + 1] =min(dp[i + 1][j + 1], t + abs(a[i] - j - 1));
			}
		}
		int ans = 1e9;
		for(int i = 0; i <= n *2; i++)
		{
			ans = min(ans, dp[n][i]);
		}
		cout << ans << "\n";
	}
	return 0;
}