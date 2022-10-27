#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;
vector <vector <pair <int, int> > > dp;
vector <vector <int> > g;
int n, m;
vector <pair <int, int> > update(vector <pair <int, int> > & a, vector <pair <int, int> > &b)
{
	vector <pair <int, int> > p(a.size() + b.size(), {-1, 0});
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
			if(b[j].second > 0)
			{
				cnt2 = b[j].first + 1;
			}
			else
			{
				cnt2 = b[j].first + (b[j].second > 0);
			}
			if(p[i + j].first < a[i].first + b[j].first || p[i + j].first == a[i].first + b[j].first && p[i + j].second < a[i].second + b[j].second)
			{
				p[i + j].first = a[i].first + b[j].first;
				p[i + j].second = a[i].second + b[j].second;
			}
			if(p[i + j + 1].first < a[i].first + cnt2 || p[i + j + 1].first == a[i].first + cnt2 && p[i + j + 1].second < a[i].second)
			{
				p[i + j + 1].first = a[i].first + cnt2;
				p[i + j + 1].second = a[i].second;
			}
		}
	}
	return p;
}
void dfs(int v, int pred = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			dfs(g[v][i], v);
			dp[v] = update(dp[v], dp[g[v][i]]);
		}
	}
}
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		dp.resize(n, vector <pair <int, int> > (1, {0, 0}));
		for(int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			dp[i][0].second -= b;
		}
		for(int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			dp[i][0].second += b;
		}
		g.resize(n);
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			cin >> x >> y;
			g[x - 1].push_back(y - 1);
			g[y - 1].push_back(x - 1);
		}
		dfs(0);
		if(dp[0][m - 1].second > 0)
		{
			dp[0][m - 1].first++;
		}
		cout << dp[0][m - 1].first << "\n";
		dp.clear();
		g.clear();
	}
	return 0;
}