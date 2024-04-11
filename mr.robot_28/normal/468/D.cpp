#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
ll ans = 0;
int n;
const int N = 3e5 + 100;
int _sz[N];
vector <pair <int, int> > g[N];
void dfs(int v, int p = -1)
{
	_sz[v] = 1;
	for(auto to : g[v])
	{
		if(to.X != p)
		{
			dfs(to.X, v);
			ans  += 1LL * 2 * to.Y * min(n - _sz[to.X], _sz[to.X]);
			_sz[v] += _sz[to.X];
		}
	}
}
int centroid(int v, int sz1, int p = -1)
{
	for(auto to : g[v])
	{
		if(to.X != p && _sz[to.X] * 2 > sz1)
		{
			return centroid(to.X, sz1, v);
		}
	}
	return v;
}
int tin[N], tout[N];
set <int> st1;
int up[N];
int timer = 0;
void dfs1(int v, int p, int pr)
{
	tin[v] = ++timer;
	up[v] = pr;
	_sz[v] = 1;
	for(auto to : g[v])
	{
		if(to.X != p){
			dfs1(to.X, v, pr);
			_sz[v] += _sz[to.X];
		}
	}
	tout[v] = timer;
}
int Tree[N * 4];
void modify(int v, int l, int r, int x, int val)
{
	if(l == r)
	{
		Tree[v] = val;
		return;
	}
	int m = (r + l) / 2;
	if(x <= m)
	{
		modify(v * 2, l, m, x, val);
	}
	else
	{
		modify(v * 2 + 1, m + 1, r, x, val);
	}
	Tree[v] = min(Tree[v * 2], Tree[v * 2 + 1]);
}
int query(int v, int l, int r, int al, int ar){
	if(l >= al && r <= ar)
	{
		return Tree[v];
	}
	int m = (r + l) / 2;
	if(al > m)
	{
		return query(v * 2 + 1, m + 1, r, al, ar);
	}
	if(ar <= m)
	{
		return query(v * 2, l, m, al, ar);
	}
	return min(query(v * 2, l, m, al, ar), query(v * 2 + 1, m + 1, r, al, ar));
}
int query(int u, int k)
{
	if(k == 0)
	{
		if(tout[u] == n)
		{
			return query(1, 1, n, 1, tin[u] - 1);
		}
		else
		{
			return min(query(1, 1, n, 1, tin[u] - 1), query(1, 1, n, tout[u] + 1, n));
		}
	}
	else
	{
		return query(1, 1, n, tin[u], tout[u]);
	}
}
int p[N];
set <int> ts[N];
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	dfs(1);
	cout << ans << "\n";
	int c = centroid(1, _sz[1]);
	tin[c] = ++timer;
	for(auto to : g[c])
	{
		dfs1(to.X, c, to.X);
		_sz[to.X] *= 2;
		if(_sz[to.X]  > n)
		{
			cout << "A";
			return 0;
		}
		ts[_sz[to.X]].insert(to.X);
	}
	tout[c] = 1;
	up[c] = c;
	for(int i = 1; i <= n; i++)
	{
		modify(1, 1, n, tin[i], i);
	}
	vector <int> must;
	for(int i = 1; i <= n; i++)
	{
		must.clear();
		for(auto it = ts[n - i + 1].begin(); it != ts[n - i + 1].end(); it++)
		{
			must.push_back(*it);
		}
		if(sz(must) == 2)
		{
			p[i] = query(must[up[i] == must[0]], 1);	
		}
		else if(sz(must) == 1)
		{
			if(up[i] == must[0])
			{
				p[i] = query(up[i], 0);
			}
			else
			{
				p[i] = query(must[0], 1);
			}
		}
		else
		{
			if(i == c)
			{
				p[i] = Tree[1];
			}
			else
			{
				p[i] = query(up[i], 0);
			}
		}
		modify(1, 1, n, tin[p[i]], 1 << 30);
		int u = up[i];
		int v = up[p[i]];
		if(u != c)
		{
			ts[_sz[u]].erase(u);
			ts[--_sz[u]].insert(u);
		}
		if(v != c)
		{
			ts[_sz[v]].erase(v);
			ts[--_sz[v]].insert(v);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << p[i] << " ";
	}
	return 0;
}