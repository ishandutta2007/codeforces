# include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, d;
	cin >> n >> m >> d;
	vector <pair <pair <int, int>, int> > f(m);
	vector <int> time;
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> f[i].first.first >> f[i].first.second >> f[i].second;
		f[i].first.first--;
		sum += f[i].first.second;
	}
	vector <int> dp(n, 0), dp1(n, 0);
	for(int i = 0; i < n; i++)
	{
		dp[i] = -abs(i - f[0].first.first);
	}
	for(int i = 1; i < m; i++)
	{
		int delta = f[i].second - f[i - 1].second;
		deque <pair <int, int> > Q;
		for(int j = 0; j < n; j++)
		{
			while(Q.size() > 0 && Q.front().first + delta * d < j)
			{
				Q.pop_front();
			}
			while(Q.size() > 0 && Q.back().second <= dp[j])
			{
				Q.pop_back();
			}
			Q.push_back({j, dp[j]});
			dp1[j] = Q.front().second;
		}
		while(Q.size() > 0)
		{
			Q.pop_back();
		}
		for(int j = n - 1; j >= 0; j--)
		{
			while(Q.size() > 0 && Q.front().first - delta * d > j)
			{
				Q.pop_front();
			}
			while(Q.size() > 0 && Q.back().second <= dp[j])
			{
				Q.pop_back();
			}
			Q.push_back({j, dp[j]});
			dp1[j] = max(dp1[j], Q.front().second);
		}
		for(int j = 0; j < n; j++)
		{
			dp[j] = dp1[j] - abs(j - f[i].first.first);
		}
	}
	int ans = -1e18;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans + sum;
	return 0;
}