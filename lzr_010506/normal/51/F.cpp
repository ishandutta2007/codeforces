#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

vi e[2010], nw[2010];
int n, m, num, top, ret, hv[2010][2010], vis[2010];
int dfn[200010], low[200010], cnt, sta[200010], bel[200010];

void tarjan(int x, int fa)
{
	dfn[x] = low[x] = ++ cnt;
	sta[++ top] = x;
	int nn = sz(e[x]);
	rep(i, 0, nn - 1)
	{
		int to = e[x][i];
		if(to == fa) continue;
		if(!dfn[to])
		{
			tarjan(to, x);
			low[x] = min(low[to], low[x]);
		}
		else low[x] = min(low[x], dfn[to]);
	}
	if(low[x] == dfn[x])
	{
		int p;
		num ++;
		do
		{
			p = sta[top --];
			bel[p] = num;
		}
		while(p != x);
	}
}

int dfs(int u, int dis, int fa, int &p)
{
	vis[u] = 1;
	p = u;
	int ret = dis;
	int nn = sz(nw[u]);
	rep(i, 0, nn - 1)
	{
		int to = nw[u][i];
		if(to == fa) continue;
		int p1, p2;
		p1 = dfs(to, dis + 1, u, p2);
		if(p1 > ret)
		{
			ret = p1;
			p = p2;
		}
	}
	return ret;
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int u, v;
		u = read();
		v = read();
		e[u].pb(v);
		e[v].pb(u);
	}
	rep(i, 1, n)
		if(!dfn[i])
			tarjan(i, 0);

	rep(i, 1, n)
	{
		int nn = sz(e[i]);
		rep(j, 0, nn - 1)
		{
			int to = e[i][j];
			int u, v;
			if(!hv[u = bel[i]][v = bel[to]] && u != v)
			{
				hv[u][v] = 1;
				nw[u].pb(v);
			}
		}
	}

	int ans = n - 1;
	rep(i, 1, num)
		if(!vis[i])
		{
			int u, v;
			dfs(i, 1, -1, u);
			int tm = dfs(u, 1, -1, v);
			if(tm != 1) ans -= tm - 3;
		}

	rep(i, 1, num)
		if (sz(nw[i]) == 1)
			ans --;
    cout << ans;
	return 0;
}