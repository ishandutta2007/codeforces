#include<bits/stdc++.h>
using namespace std;

signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int n, m;
  	cin >> n >> m;
  	vector <int> x(m);
  	for(int i = 0; i < m; i++)
  	{
  		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int g, r;
	cin >> g >> r;
	vector <vector <int> > dp(m, vector <int> (g + 1, 1e9));
	dp[0][g] = 0;
	deque <pair <int, pair <int, int> > > q;
	q.push_front({0, {0, g}});
	while(q.size() != 0)
	{
		pair <int, int> v = q.front().second;
		int val = q.front().first;
		q.pop_front();
		if(val != dp[v.first][v.second])
		{
			continue;
		}
		if(v.second == 0)
		{
			if(dp[v.first][g] > val + r)
			{
				dp[v.first][g] = val + r;
				q.push_back({dp[v.first][g], {v.first, g}});
			}
		}
		else
		{
			if(v.first > 0)
			{
				int leftd = x[v.first] - x[v.first - 1];
				if(leftd <= v.second && dp[v.first - 1][v.second - leftd] > dp[v.first][v.second] + leftd)
				{
					dp[v.first - 1][v.second - leftd]  =dp[v.first][v.second] + leftd;
					q.push_front({dp[v.first - 1][v.second - leftd], {v.first - 1, v.second - leftd}});
				}
			}
			if(v.first < m - 1)
			{
				int rightd = x[v.first + 1] - x[v.first];
				if(rightd <= v.second && dp[v.first + 1][v.second - rightd] > dp[v.first][v.second] + rightd)
				{
					dp[v.first + 1][v.second - rightd] = dp[v.first][v.second] + rightd;
					q.push_front({dp[v.first + 1][v.second - rightd], {v.first + 1, v.second - rightd}});
				}
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i <= g; i++)
	{
		ans = min(ans, dp[m - 1][i]);
	}
	if(ans == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
    return 0;
}