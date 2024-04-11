#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> sz;
vector <int> dp;
int n;
int ans = 1e18;
struct Line{
	double k, b, l, r;
};
vector <Line> cht;
int query(int x)
{
	int L = 0, R = cht.size();
	int x1 = x;
	while(R - L > 1)
	{
		int midd = (R + L) / 2;
		if(cht[midd].r >= x1)
		{
			L = midd;
		}
		else
		{
			R = midd;
		}
	}
	int k = cht[L].k, b = cht[L].b;
	return k * x + b;
}
double intersection(Line a, Line b)
{
	if(a.k == b.k)
	{
		return -1e18;
	}
	return (a.b - b.b) / (b.k - a.k);
}
void add(int k, int b)
{
	Line New = {k, b, -1e18, 1e18};
	while(cht.size())
	{
		double inter = intersection(New, cht.back());
		if(inter <= cht.back().l)
		{
			cht.pop_back();
		}
		else
		{
			cht.back().r = inter;
			New.l = inter;
			cht.push_back(New);
			break;
		}
	}
	if(cht.size() == 0)
	{
		cht.push_back(New);
	}
}
void calculate(int v, int pred)
{
	vector <pair <int, int> > child;
	int cur = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			child.push_back({sz[g[v][i]], dp[g[v][i]]});
			cur++;
		}
	}
	if(cur == 1)
	{
		return;
	}

	sort(child.begin(), child.end(), greater<pair <int, int> > ());
	for(int i = 0; i < child.size(); i++)
	{
		int sz = child[i].first, DP = child[i].second;
		if(i > 0)
		{
			int res = query(sz);
			ans = min(ans, res + DP + n * n + sz * sz - 2 * n * sz);
		}
		int k = 2 * sz;
		int b = DP + sz * sz - n * sz * 2;
		add(k, b);
	}
}
void dfs(int v, int pred = -1)
{
	sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(pred != g[v][i])
		{
			dfs(g[v][i], v);
			sz[v] += sz[g[v][i]];
		}
	}
	if(sz[v] == 1)
	{
		dp[v] = 1;
	}
	else
	{
		dp[v] = 1e18;
		for(int i = 0; i < g[v].size(); i++)
		{
			if(pred != g[v][i])
			{
				int to = g[v][i];
				dp[v] = min(dp[v], dp[to] + (sz[v] - sz[to]) * (sz[v] - sz[to]));
			}
		}
	}
	calculate(v, pred);
}
signed main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	sz.resize(n);
	g.resize(n);
	dp.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(n == 2)
	{
		cout << 2;
		return 0;
	}
	int stx = 0;
	for(int i = 0; i < g.size(); i++)
	{
		if(g[i].size() >= 2)
		{
			stx = i;
			break;
		}
	}
	dfs(stx, -1);
	int rez = n * (n - 1) - (ans - n) / 2;
	cout << rez;
}