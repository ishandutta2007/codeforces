#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, n;
	cin >> r >> n;
	vector <int> dp(n, 0);
	vector <pair <int, int> > x(n);
	vector <int> tim(n);
	int it = 0;
	int ans = -1;
	int allans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> tim[i];
		cin >> x[i].first >> x[i].second;
		if(abs(x[i].first - 1) + abs(x[i].second - 1) <= tim[i])
		{
			dp[i] =1 ;
		}
		while(tim[it] + 2000 <= tim[i])
		{
			ans = max(ans, dp[it]);
			it++;
		}
		for(int j = i - 1; j >= it; j--)
		{
			int s = abs(x[j].first - x[i].first) + abs(x[i].second - x[j].second);
			if(s + tim[j] <= tim[i])
			{
				if(dp[j] != 0)
				{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			}
		}
		dp[i] = max(dp[i], ans + 1);
		allans = max(allans, dp[i]);
	}
	cout << allans;
	return 0;
}