#include <bits/stdc++.h>
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ll long long
const int mod = 998244353;
inline void update(int &x, int y) { x += y; if(x >= mod) x -= mod; }
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 2e5 + 10;
int p, Dep;
int n, dep[N], f[N], fa[N][20], sz[N], u[N], v[N], sum[N];
vector<int> a[N];

void dfs(int x, int f)
{
    dep[x] = dep[f] + 1;
    Dep = max(Dep, dep[x]);
    sz[x] = 1;
    fa[x][0] = f;
    int nn = a[x].size();
    rep(i, 0, nn - 1)
    {
        int to = a[x][i];
        if(to == f) continue;
        dfs(to, x);
        sz[x] += sz[to];
    }
}


int lca(int u, int v)
{
	if(u == v) return u;
	if(dep[u] > dep[v]) swap(u, v);
	int len = dep[v] - dep[u];
	rrep(i, p, 0)
	{
	    int l = 1 << i;
        if(l > len) continue;
        len -= l;
        v = fa[v][i];
	}
	if(u == v) return u;
	rrep(i, p, 0)
	{
        if(fa[u][i] == fa[v][i]) continue;
        u = fa[u][i];
        v = fa[v][i];
	}
	return fa[u][0];
}

void dfs1(int x, int fa)
{
	sum[x] = f[x];
	int nn = a[x].size();
	rep(i, 0, nn - 1)
	{
		int to = a[x][i];
		if(to == fa) continue;
		dfs1(to, x);
		sum[x] += sum[to];
	}
}

int main()
{
	n = read();
	rep(i, 1, n - 1)
	{
		u[i] = read();
		v[i] = read();
		a[u[i]].pb(v[i]);
		a[v[i]].pb(u[i]);

	}
	dfs(1, 0);
	while((1 << p) <= Dep) p ++;
	rep(i, 1, p)
        rep(j, 1, n)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
	int Q = read();
	while(Q --)
	{
		int u, v;
		u = read();
		v = read();
		f[u] ++;
		f[v] ++;
       // cout << lca(u, v) << endl;
		f[lca(u, v)] -= 2;
	}


	dfs1(1, 0);
	rep(i, 1, n - 1)
	{
		int x = u[i];
		int y = v[i];
		if(dep[x] < dep[y]) printf("%d ", sum[y]);
		else printf("%d ", sum[x]);
	}

	return 0;
}