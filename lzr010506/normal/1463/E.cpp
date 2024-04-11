#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
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
const int N = 400010;
const int MAXLOGN = 22;
int root, n, k, fa[N], x[N], y[N];
vector<int> FROM[N], TO[N];
int p[N];
vector<int> save[N], G[N], T[N];
bool vis[N];
int Col[N];
bool flag;
vector<int> Ans;
int pa[MAXLOGN][N];
int Dep[N];
void dfs(int v, int p)
{
	pa[0][v] = p;
	Dep[v] = Dep[p] + 1;
	for(auto to : T[v])
	{
		if(to == p) continue;
		dfs(to, v);
	}
}
int get(int v, int x)
{
	rep0(k, MAXLOGN)
		if ((x >> k) & 1)
			v = pa[k][v];
	return v;
}
int lca(int u, int v)
{
	if (Dep[u] > Dep[v]) swap(u, v);
	v = get(v, Dep[v] - Dep[u]);
	if (u == v) return u;
	rrep(k, MAXLOGN - 1, 0)
		if (pa[k][u] != pa[k][v])
		{
			u = pa[k][u];
			v = pa[k][v];
		}
	
	return pa[0][u];
}
int dis(int u, int v)
{
	return Dep[u] + Dep[v] - 2 * Dep[lca(u, v)];
}
void dfs1(int v)
{
	Col[v] = 1;
	for(auto to : G[v])
	{
		if (Col[to] == 0) dfs1(to);
		else if (Col[to] == 1) flag = false;
	}
	Col[v] = 2;
	Ans.pb(v);
}
int main()
{
	n = read();
	k = read();
	rep(i, 1, n)
	{
		fa[i] = read();
		if (fa[i]) T[fa[i]].pb(i); 
		else root = i;
	}
	dfs(root, 0);
	rep0(k, MAXLOGN - 2)
		rep(v, 1, n)
			if (pa[k][v] < 0) pa[k + 1][v] = -1;
			else pa[k + 1][v] = pa[k][pa[k][v]];
		
	rep(i, 1, k)
	{
		x[i] = read();
		y[i] = read();
		FROM[x[i]].pb(y[i]);
		TO[y[i]].pb(x[i]);
	}
	rep(i, 1, k)
		if (lca(x[i], y[i]) == y[i])
		{
			puts("0");
			return 0;
		}
	rep(i, 1, n)
		if (FROM[i].size() > 1 || TO[i].size() > 1)
		{
			puts("0");
			return 0;
		}
	
	memset(vis, false, sizeof(vis));
	rep(i, 1, n)
	{
		if (!FROM[i].size() && !TO[i].size()) {p[i] = i; vis[i] = true; save[i].pb(i);}
		else if (FROM[i].size() && !TO[i].size())
		{
			int now = i;
			while (true)
			{
				if (vis[now])
				{
					puts("0");
					return 0;
				}
				vis[now] = true;
				save[i].pb(now);
				p[now] = i;
				if (FROM[now].size()) now = FROM[now][0]; else break;
			}
		}
	}
	rep(i, 1, n)
		if (!vis[i]) {puts("0"); return 0;}
	rep(i, 1, n)
		if (fa[i])
			if (p[i] != p[fa[i]]) G[p[fa[i]]].pb(p[i]);
	flag = true;
	memset(Col, 0, sizeof(Col));
	rep(i, 1, n)
		if (p[i] == i && Col[i] == 0)
			dfs1(i);
	if (!flag) {puts("0"); return 0;}
	reverse(ALL(Ans));
	for (auto x : Ans)
		for (auto y : save[x])
			printf("%d ", y);
	puts("");
	return 0;
}