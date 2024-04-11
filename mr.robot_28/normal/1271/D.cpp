#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <pair <pair <int,int>, int> > A;
signed main()
{
	int n, m, k;
	cin >> n >> m >> k;
	A.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first.first >> A[i].first.second >> A[i].second;
	}
	vector <int> right(n);
	for(int i = 0; i < n; i++)
	{
		right[i] = i;
	}
	vector <vector <int> > g(n);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		right[y - 1] = max(right[y - 1], x - 1);
	}
	for(int i = 0; i < n; i++)
	{
		g[right[i]].push_back(i);
	}
	vector <int> dp(n + 1, 0);
	int sum = k;
	vector <int> dp1(n + 1);
	int cnt1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(sum < A[i].first.first)
		{
			cout << -1;
			return 0;
		}
		else
		{
			sum += A[i].first.second;
			if(i != n - 1)
			{
				if(sum < A[i + 1].first.first)
				{
					cout << -1;
					return 0;
				}
				for(int j = 0; j < g[i].size(); j++)
				{
					for(int cnt = 0; cnt <= n; cnt++)
					{
						dp1[cnt] = dp[cnt];
					}
					for(int cnt = 0; cnt < min(min(n, cnt1 + 1), sum - A[i + 1].first.first); cnt++)
					{
						dp1[cnt + 1] = max(dp1[cnt + 1], dp[cnt] + A[g[i][j]].second); 
					}
					for(int cnt = 0; cnt <= min(n, cnt1 + 1); cnt++)
					{
						dp[cnt] = dp1[cnt];
					}
					for(int cnt = min(min(cnt1 + 1, n), sum - A[i + 1].first.first) + 1; cnt <= n; cnt++)
					{
						dp[cnt] = 0;
					}
					cnt1++;
				}
				for(int cnt = min(min(cnt1 + 1, n), sum - A[i + 1].first.first) + 1; cnt <= n; cnt++)
				{
					dp[cnt] = 0;
				}
			}
			else
			{
				for(int j = 0; j < g[i].size(); j++)
				{
					for(int cnt = 0; cnt <= n; cnt++)
					{
						dp1[cnt] = dp[cnt];
					}
					for(int cnt = 0; cnt < min(min(n, cnt1 + 1), sum); cnt++)
					{
						dp1[cnt + 1] = max(dp1[cnt + 1], dp[cnt] + A[g[i][j]].second);
					}
					for(int cnt = 0; cnt <= min(min(n, cnt1 + 1), sum); cnt++)
					{
						dp[cnt] = dp1[cnt];
					}
					for(int cnt = min(min(n, cnt1  + 1), sum) + 1; cnt <= n; cnt++)
					{
						dp[cnt]  = 0;
					}
					cnt1++;
				}
			}
		}
	}
	int ans = 0;
	for(int cnt = 0; cnt <= n;cnt++)
	{
		ans = max(ans, dp[cnt]);
	}
	cout << ans;
	return 0;
}