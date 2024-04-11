#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = -1e9;
	vector <vector <int> > dp(n, vector <int> (61, -1e9));
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			dp[i][a[i] + 30] = a[i];
 		}
		else
		{
			dp[i][a[i] + 30] = a[i];
			for(int j = 0; j < 61; j++)
			{
				dp[i][max(a[i] + 30, j)] = max(dp[i][max(a[i] + 30, j)], dp[i - 1][j] + a[i]);
			}
		}
		for(int j = 0; j < 61; j++)
		{
			ans = max(ans, dp[i][j] - (j - 30));
		}
	}
	cout << ans;
    return 0;
}