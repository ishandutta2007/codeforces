#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > a(n);
	vector <vector <bool> > dp(n + 1, vector <bool> (k, false));
	long long sum = 0;
	dp[0][0] = true;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	int sum1 = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			if(!dp[i][j])
			{
				continue;
			}
			for(int d = 0; d < min(k, a[i].first + 1); d++)
			{
				int to = (k - (a[i].first - d) % k) % k;
				if(to > a[i].second)
				{
					continue;
				}
				dp[i + 1][(j + d) % k] = true;
			}
		}
		sum += a[i].first;
		sum += a[i].second;
	}
	long long ans = 0;
	for(int i = 0; i < k; i++)
	{
		if(dp[n][i] && (sum - i) / k > ans)
		{
			ans = (sum - i) / k;
		}
	}
	cout << ans;
	return 0;
}