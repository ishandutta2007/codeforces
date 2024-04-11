#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X fisrt
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 100010;

struct E
{
	int to,next,id;
}E[N << 1];
struct L
{
	int x,y;
	L(){}
	L(int x,int y):x(x),y(y){}
}e[N << 1];
int n,t,num,m,x,y,sig,cnt,ans,z;
int head[N],f[N][18],dep[N],sz[N],a[N],vis[N],w[N],up[N];
bool tag[N];
vector<int> G[N];

void add(int x,int y,int id)
{
	E[++ num].to = y;
	E[num].next = head[x];
	E[num].id = id;
	head[x] = num;
}

void dfs1(int k,int fa)
{
	vis[k] = 1;
	for (int j = head[k]; j; j = E[j].next)
	{
		int u = E[j].to;
		if (u == fa || vis[u]) continue;
		G[k].pb(u);
		tag[E[j].id] = 1;
		dep[u] = dep[k] + 1;
		f[u][0] = k;
		w[u] = E[j].id;
		dfs1(u, k);
	}
}

void init()
{
	rep(i, 1, 17)
		rep(j, 1, n)
			f[j][i] = f[f[j][i - 1]][i - 1];
}

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	rrep(i, 17, 0)
		if (dep[x] - dep[y] >= (1 << i)) x = f[x][i];
	if (x == y) return x;
	rrep(i, 17, 0)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

void dfs2(int k,int fa)
{
	vis[k] = 1;
	int nn = G[k].size();
	rep(j, 0, nn - 1)
	{
		int u = G[k][j];
		if (u == fa || vis[u]) continue;
		dfs2(u, k);
		sz[k] += sz[u];
	}
}

void dfs3(int k, int fa)
{
	vis[k] = 1;
	if (sz[k] != 1) up[k] = dep[k];
	int nn = G[k].size();
	rep(i, 0, nn - 1)
	{
		int u = G[k][i];
		if (u == fa || vis[u]) continue;
		up[u] = up[k];
		dfs3(u, k);
	}
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int x = read();
		int y = read();
		add(x, y, i);
		add(y, x, i);
		e[i] = L(x, y);
	}
	rep(i, 1, n)
		if (!vis[i]) dfs1(i, 0);
	init();
	rep(i, 1, m)
		if (!tag[i])
		{
			x = e[i].x;
			y = e[i].y;
			z = lca(x, y);
			sz[x] ++;
			sz[y] ++;
			sz[z] -= 2;
		}
	memset(vis, 0, sizeof(vis));
	rep(i, 1, n)
		if (!vis[i])
			dfs2(i, 0);
	memset(vis, 0, sizeof(vis));
	rep(i, 1, n)
		if (!vis[i])
			dfs3(i, 0);
	rep(i, 1, m)
		if(!tag[i])
		{
			x = e[i].x;
			y = e[i].y;
			z = lca(x, y);
			if (up[x] <= dep[z] && up[y] <= dep[z])
			{
				a[++ ans] = i;
				while (x != z)
				{
					a[++ ans] = w[x];
					x = f[x][0];
				}
				while (y != z)
				{
					a[++ ans] = w[y];
					y = f[y][0];
				}
			}
		}
	sort(a + 1, a + 1 + ans);
	printf("%d\n", ans);
	rep(i, 1, ans) printf("%d ", a[i]);
	return 0;
}