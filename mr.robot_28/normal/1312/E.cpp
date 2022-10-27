#include<bits/stdc++.h>
using namespace std;
signed main() {
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
	vector <vector <int> > dp(n, vector <int> (n + 1, -1));
	for(int i = 0; i < n; i++)
	{
		dp[i][1] = a[i];
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = j + 1; k < n && i - (k - j) > 0; k++)
			{
				if(dp[j][k - j] == dp[k][i - (k - j)] && dp[j][k - j] != -1)
				{
					dp[j][i] = dp[j][k - j] + 1;
				}
			}
		}
	}
	vector <vector <int> > g(n + 1);
	vector <int> d(n + 1, -1);
	for(int i = 0; i < n; i++)
	{
		for(int len = 1; len <= n; len++)
		{
			if(dp[i][len] != -1)
			{
				g[i].push_back(i + len);
			}
		}
	}
	queue <int> q;
	q.push(0);
	d[0] = 0;
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		if(v == n)
		{
			break;
		}
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(d[to] == -1)
			{
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	cout << d[n];
	return 0;
}