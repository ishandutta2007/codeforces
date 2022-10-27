#include<bits/stdc++.h>
using namespace std;
int n, m;
#define int long long
vector <vector <int> > g;
vector <int> dp;
vector <vector <int> > pred;
int t;
int timer = 0;
vector <int> tin, tout;
void dfs(int v)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
		pred[to][0] = v;
	}
	tout[v] = timer++;
}
bool pr(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
vector <vector <vector <int> > > query;
vector <int> ind;
vector <int> fenv;
int ans(int x)
{
	int sum = 0;
	while(x >= 0)
	{
		sum += fenv[x];
		x = (x & (x + 1)) - 1;
	}
	return sum;
}
void update(int x, int val)
{
	if(x == -1)
	{
		return;
	}
	while(x < 2 * n)
	{
		fenv[x] += val;
		x = x | (x + 1);
	}
}
void dfs1(int v)
{
	int sum1 = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs1(g[v][i]);
		sum1 += dp[g[v][i]];
	}
	dp[v] = sum1;
	for(int i = 0; i < query[v].size(); i++)
	{
		int a = query[v][i][2];
		int b = query[v][i][3];
		int a1 = query[v][i][0];
		int b1 = query[v][i][1];
		int c = query[v][i][4];
		int sum = c;
		if(a != v)
		{
			sum += ans(tin[a]) - ans(tin[v]);
		}
		if(b != v)
		{
			sum += ans(tin[b]) - ans(tin[v]);
		}
		sum += ans(tin[v]);
		if(v != 0)
		{
		  sum -= ans(tin[pred[v][0]]);
		}
		dp[v] = max(dp[v], sum);
	}
	update(tin[v], -dp[v]);
	update(tout[v], dp[v]);
	update(tin[pred[v][0]], dp[v]);
	update(tout[pred[v][0]], -dp[v]);
}
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	g.resize(n);
	fenv.resize(2 * n);
	ind.resize(n);
	t = log2(n) + 1;
	tin.resize(n);
	query.resize(n);
	tout.resize(n);
	pred.resize(n, vector <int> (t));
	dp.resize(n);
	for(int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		x--;
		g[x].push_back(i);
	}
	pred[0][0] = 0;
	dfs(0);
	for(int i = 1; i < t; i++)
	{
		for(int j = 0; j < n; j++)
		{
			pred[j][i] = pred[pred[j][i - 1]][i - 1];
		}
	}
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		int a2 = a, b2 = b;
		int a1 = a;
		for(int j = t - 1; j >= 0; j--)
		{
			if(!pr(pred[a1][j], b))
			{
				a1 = pred[a1][j];
			}
		}
		if(!pr(a1, b))
		{
			a1 = pred[a1][0];
		}
		for(int j = t - 1; j >= 0; j--)
		{
			if(!pr(pred[a][j], b))
			{
				a = pred[a][j];
			}
		}
		for(int j = t - 1; j >= 0; j--)
		{
			if(!pr(pred[b][j], a))
			{
				b = pred[b][j];
			}
		}
		query[a1].push_back({a, b, a2, b2, c});
	}
	dfs1(0);
	cout << dp[0];
    return 0;
}