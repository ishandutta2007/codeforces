#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
#define ll long long
const int N = 2e5;
const int T = 20;
int n, q;
vector <int> g[N];
vector <pair <int, int> > g1[N];
int h[N];
int used[N];
int up[T][N];
int tin[N], tout[N];
int timer = 0;
bool pred(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
	if(pred(a, b))
	{
		return a;
	}
	for(int j = T - 1; j >= 0; j--)
	{
		if(!pred(up[j][a], b))
		{
			a = up[j][a];
		}
	}
	return up[0][a];
}
void dfs(int v, int p = -1)
{
	tin[v] = timer++;
	for(auto to : g[v])
	{
		if(to == p)
		{
			continue;
		}
		h[to] = h[v] + 1;
		up[0][to] = v;
		dfs(to, v);
	}
	tout[v] = timer++;
}
bool cmp1(int a, int b)
{
	return tin[a] < tin[b];
}
int num[N];
int ans_node[N];
pair <int, int> dp_down[N], dp_up[N];
int s[N];
bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.X == -1)
	{
		return 0;
	}
	if(b.X == -1)
	{
		return 1;
	}
	int k1 = (a.Y + s[a.X] - 1) / s[a.X];
	int k2 = (b.Y + s[b.X] - 1) / s[b.X];
	if(k1 == k2)
	{
		return a.X < b.X;
	}
	return k1 < k2;
}
pair <int, int> best(pair <int, int> a, pair <int, int> b, pair <int, int> c)
{
	if(cmp(a, b) && cmp(a, c))
	{
		return a;
	}
	if(cmp(b, a) && cmp(b, c))
	{
		return b;
	}
	return c;
}
void dfs_calc_down(int v)
{
	dp_down[v] = {-1, -1};
	for(auto to : g1[v])
	{
	//	cout << to.X << '\n';
		dfs_calc_down(to.X);
		pair <int, int> p = dp_down[to.X];
		p.Y += to.Y;
		if(cmp(p, dp_down[v]))
		{
			dp_down[v] = p;
		}
	}
	if(used[v] && cmp({used[v] - 1, 0}, dp_down[v]))
	{
		dp_down[v] = {used[v] - 1, 0};
	}
}
void dfs_calc_up(int v)
{
	vector <pair <int, int> > pref(sz(g1[v]) + 1, {-1, -1}), suf(sz(g1[v]) + 1, {-1, -1});
	for(int i = 0; i < sz(g1[v]); i++)
	{
		int to = g1[v][i].X;
		pair <int, int> p = dp_down[to];
		p.Y += g1[v][i].Y;
		if(cmp(p, pref[i]))
		{
			pref[i + 1] = p;
		}
		else
		{
			pref[i + 1] = pref[i];
		}
	}
	for(int i = sz(g1[v]) - 1; i >= 0; i--)
	{
		int to = g1[v][i].X;
		pair <int, int> p = dp_down[to];
		p.Y += g1[v][i].Y;
		if(cmp(p, suf[i + 1]))
		{
			suf[i] = p;
		}
		else
		{
			suf[i] = suf[i + 1];
		}
	}
	if(used[v] && cmp({used[v] - 1, 0}, dp_up[v]))
	{
		dp_up[v] = {used[v] - 1, 0};
	}
	if(cmp(dp_down[v], dp_up[v]))
	{
		ans_node[v] = dp_down[v].X;
	}
	else
	{
		ans_node[v] = dp_up[v].X;
	}
	for(int i = 0; i < sz(g1[v]); i++)
	{
		int to = g1[v][i].X;
		pair <int, int> p = dp_up[v];
		pair <int, int> p1 = pref[i];
		pair <int, int> p2 = suf[i + 1];
		dp_up[to] = best(p, p1, p2);
		dp_up[to].Y += g1[v][i].Y;
	}
	for(auto to : g1[v])
	{
		dfs_calc_up(to.X); 
	}
}
vector <int> vertex;
int go_to(int l, int r)
{
	if(l == r)
	{
		return vertex[l];
	}
	int a = lca(vertex[l], vertex[r]);
	int l1 = l, r1 = r;
	while(r1 - l1 > 1)
	{
		int midd1 = (l1 + r1) / 2;
		if(lca(vertex[l], vertex[midd1]) != a)
		{
			l1 = midd1;
		}
		else
		{
			r1 = midd1;
		}
	}
	int b = go_to(l, l1);
	int c = go_to(l1 + 1, r);
	if(b != a)
	{
		g1[a].push_back({b, h[b] - h[a]});
	}
	if(c != a)
	{
		g1[a].push_back({c, h[c] - h[a]});
	}
	vertex.push_back(a);
	return a;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	for(int j = 1; j < T; j++)
	{
		for(int i = 0; i < n; i++)
		{
			up[j][i] = up[j - 1][up[j - 1][i]];
		}
	}
	cin >> q;
	while(q--)
	{
		int k, m;
		cin >> k >> m;
		set <pair <int, int> > st;
		vector <int> ver1(k), ver2(m);
		vertex.clear();
		for(int i = 0; i < k; i++)
		{
			cin >> ver1[i];
			ver1[i]--;
			cin >> s[i];
			vertex.push_back(ver1[i]);
		}
		for(int i = 0; i < m; i++)
		{
			cin >> ver2[i];
			ver2[i]--;
			vertex.push_back(ver2[i]);
		}
		sort(vertex.begin(), vertex.end(), cmp1);
		int lst = go_to(0, sz(vertex) - 1);
		for(int i = 0; i < sz(ver1); i++)
		{
			num[ver1[i]] = i;
			used[ver1[i]] = i + 1;
		}
		for(auto v : vertex)
		{
			dp_down[v] = dp_up[v] = {-1, -1};
		}
		dfs_calc_down(lst);
		dfs_calc_up(lst);
		for(auto i : vertex)
		{
			g1[i].clear();
		}
		for(auto v : ver2)
		{
			cout << 1 + ans_node[v] << " ";
		}
		for(auto v : vertex)
		{
			used[v] = num[v] = 0;
		}
		cout << "\n";
	}
	return 0;
}