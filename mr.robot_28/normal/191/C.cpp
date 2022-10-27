#include<bits/stdc++.h>
using namespace std;
int n;
vector <vector <pair <int, int> > > g;
vector <int> tree;
vector <vector <int> > pred, updates;
vector <int> tin, tout, answer;
int timer = 0;
void dfs(int v, int p = -1)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != p)
		{
			pred[to][0] = v;
			dfs(to, v);
		}
	}
	tout[v] = timer++;
}
int t;
bool pr(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
	if(pr(a, b))
	{
		return a;
	}
	for(int j = t - 1; j >= 0; j--)
	{
		if(!pr(pred[a][j], b))
		{
			a = pred[a][j];
		}
	}
	return pred[a][0];
}
void update(int v, int l, int r, int ind)
{
	tree[v]++;
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(al <= l && r <= ar)
	{
		return tree[v];
	}
	else if(al <= r && ar >= l)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
void dfs1(int v, int p = -1)
{
	for(int i = 0; i < updates[v].size(); i++)
	{
		update(1, 0, timer -1, tin[updates[v][i]]);
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int ind = g[v][i].second;
		if(to != p)
		{
			answer[ind] = ans(1, 0, timer - 1, tin[to], tout[to]); 
			dfs1(to, v);
		}
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	t = log2(n) + 1;
	pred.resize(n, vector <int> (t));
	tin.resize(n);
	tout.resize(n);
	updates.resize(n);
	g.resize(n);
	answer.resize(n - 1);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	dfs(0);
	for(int j = 1; j < t; j++)
	{
		for(int i = 0;  i < n; i++)
		{
			pred[i][j] = pred[pred[i][j - 1]][j - 1];
		}
	}
	tree.resize(4 * timer);
	int q;
	cin >> q;
	while(q--)
	{
		int a, b;
		cin >>  a >> b;
		a--;
		b--;
		int k = lca(a, b);
		updates[k].push_back(a);
		updates[k].push_back(b);
	}
	dfs1(0);
	for(int i = 0; i  < n - 1; i++)
	{
		cout << answer[i] << " ";
	}
    return 0;
}