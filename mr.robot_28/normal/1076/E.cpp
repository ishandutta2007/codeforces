#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <vector <pair <int, int> > > updates;
vector <int> tree;
vector <int> ans;
int n;
void update(int v, int l, int r, int al, int ar, int val)
{
	if(al <= l && ar >= r)
	{
		tree[v] += val;
		return;
	}
	if(al <= r && ar >= l)
	{
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int answer(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return tree[v];
	}
	if(ind <= (r + l) / 2)
	{
		return tree[v] + answer(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		return tree[v] + answer(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
void dfs(int v, int pred = -1, int h = 0)
{
	for(int i = 0; i < updates[v].size(); i++)
	{
		update(1, 0, n - 1, h, min(updates[v][i].second + h, n), updates[v][i].first);
	}
	ans[v] = answer(1, 0, n - 1, h);
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			dfs(g[v][i], v, h + 1);
		}
	}
	for(int i = 0; i < updates[v].size(); i++)
	{
		update(1, 0, n - 1, h, min(updates[v][i].second + h, n), -updates[v][i].first);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	tree.resize(n * 4);
	g.resize(n);
	ans.resize(n);
	updates.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int v, x, d;
		cin >> v >> d >> x;
		v--;
		updates[v].push_back({x, d});
	}
	dfs(0);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}