#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> a;
vector <vector <int> > dp;
void dfs(int v)
{
	if(g[v].size() == 0)
	{
		dp[v][0] = 0;
		dp[v][1] = a[v];
		return;
	}
	int sum1 = 0;
	int sum2 = 0;
	int m1 = 1e18, m2 = 1e9;
	int c = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
		if(dp[to][0] > dp[to][1])
		{
			sum1 += dp[to][0];
			m1 = min(m1, dp[to][0] - dp[to][1]);
		}
		else
		{
			sum1 += dp[to][1];
			c++;
			m1 = min(m1, dp[to][1] - dp[to][0]);
		}
	}
	if(c % 2 == 1)
	{
		dp[v][0] = sum1 - m1;
		dp[v][1] = sum1 - m1 + a[v];
		dp[v][1] = max(dp[v][1], sum1);
	}
	else
	{
		dp[v][0] = sum1;
		dp[v][1] = sum1 + a[v];
		dp[v][1] = max(dp[v][1], sum1 - m1);
	}
	dp[v][1] = max(dp[v][1], a[v]);
}
signed main()
{
 //   ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
   	int n;
   	cin >> n;
   	g.resize(n);
   	a.resize(n);
   	dp.resize(n, vector <int> (2, 0));
	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		cin >> a[i];
		if(p != -1)
		{
			p--;
			g[p].push_back(i);
		}
	}
	dfs(0);
	cout << max(dp[0][0], dp[0][1]);
    return 0;
}