#include<bits/stdc++.h>
using namespace std;
vector <vector <pair <int, int> > > g;
vector <int> h, hmax;
int w = 0;
void dfs(int v, int p = -1)
{
	if(h[v] > h[w])
	{
		w = v;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != p)
		{
			h[to] = h[v] + 1;
			dfs(to, v);
		}
	}
}
vector <int> tree0, tree1, upd;
vector <pair <int, int> >  mass;
vector <int> tin, tout;
bool pred(int a,int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int w1 = 0;
void dfs1(int v, int m = 0, int p = -1)
{
	mass.push_back({m, h[v]});
	if(h[v] > h[w1])
	{
		w1 = v;
	}
	tin[v] = mass.size() - 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != p)
		{
			h[to] = h[v] + 1;
			dfs1(to, m ^ g[v][i].second, v);
		}
	}
	tout[v] = mass.size() - 1;
}
void build(int v, int l, int r)
{
	upd[v] = 0;
	if(l == r)
	{
		tree0[v] = tree1[v] = 0;
		if(mass[l].first == 0)
		{
			tree0[v] = mass[l].second;
		}
		else
		{
			tree1[v] = mass[l].second;
		}
		return;
	}
	build(v * 2 , l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
	tree0[v] = max(tree0[v * 2], tree0[v * 2 + 1]);
	tree1[v] = max(tree1[v * 2], tree1[v * 2 + 1]);
}
void push(int v, int l, int r)
{
	if(upd[v])
	{
		upd[v * 2] ^= 1;
		upd[v * 2 + 1] ^= 1;
		upd[v] = 0;
		swap(tree0[v * 2], tree1[v * 2]);
		swap(tree0[v * 2 + 1], tree1[v * 2 + 1]);
	}
}
void update(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		upd[v] ^= 1;
		swap(tree0[v], tree1[v]);
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		tree0[v] = max(tree0[v * 2], tree0[v * 2 + 1]);
		tree1[v] = max(tree1[v * 2], tree1[v * 2 + 1]);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	h.resize(n);
	tin.resize(n);
	tout.resize(n);
	g.resize(n);
	tree0.resize(4 * n);
	tree1.resize(4 * n);
	upd.resize(4 * n);
	vector <pair <int, int> > mass1(n);
	for(int i = 0; i < n - 1;i++)
	{
		int a, b, t;
		cin >> a>> b >> t;
		a--;
		b--;
		mass1[i] = {a, b};
		g[a].push_back({b, t});
		g[b].push_back({a, t});
	}
	dfs(0);
	h[w] = 0;
	dfs1(w);
	build(1, 0, n - 1);
	int m;
	cin >> m;
	vector <int> ans(m);
	vector <int> quer(m);
	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		a--;
		quer[i] = a;
		int u = mass1[a].first;
		int v = mass1[a].second;
		if(pred(v, u))
		{
			swap(u, v);
		}
		update(1, 0, n - 1, tin[v], tout[v]);
		ans[i] = tree0[1];
	}
	while(mass.size() > 0)
	{
		mass.pop_back();
	}
	h[w1] = 0;
	dfs1(w1);
	build(1, 0, n - 1);
	for(int i = 0; i < m; i++)
	{
		int a = quer[i];
		int u = mass1[a].first;
		int v = mass1[a].second;
		if(pred(v, u))
		{
			swap(u, v);
		}
		update(1, 0, n - 1, tin[v], tout[v]);
//		cout << tree0[1] << " ";
		ans[i] = max(ans[i], tree0[1]);
		cout << ans[i] << "\n";
	}
	return 0;
}