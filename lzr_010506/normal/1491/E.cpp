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
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define Alsls(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = 2e5 + 10;
int n, _n, zx, gg, k, f[N], siz[N], mx[N], vis[N], ww, e[N];
vector<pii> G[N];
 
 
void findCore(int u, int fa) 
{
    siz[u] = 1; 
    mx[u] = 0;
    rep0(i, sz(G[u]))
	{
        int v = G[u][i].X, w = G[u][i].Y;
        if(v == fa) continue;
        if(vis[w]) continue;
        //vis[w] = 1;
        findCore(v, u);
        siz[u] += siz[v];
        mx[u] = max(mx[u], siz[v]);
    }
    mx[u] = max(mx[u], _n - siz[u]);
    if (zx == -1 || mx[zx] > mx[u]) zx = u; 
}
 
int Findzx(int u, int n) 
{
    _n = n; 
    zx = -1;
    findCore(u, u);
    return zx;
}
 
void dfs(int u, int fa) 
{
    siz[u] = 1;
    rep0(i, sz(G[u]))
	{
        int v = G[u][i].X, w = G[u][i].Y;
        if(v == fa) continue;
        if(vis[w]) continue;
        e[v] = w;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
void find(int u, int fa, int w) 
{
    if (siz[u] == f[k - 1] || siz[u] == f[k - 2]) gg = u, ww = w;
    rep0(i, sz(G[u]))
	{
        int v = G[u][i].X, w = G[u][i].Y;
        if(v == fa) continue;
        if(vis[w]) continue;
        find(v, u, w);
    }
}
 
void solve(int u, int n) 
{
    if (n == 1) return;
    k = lower_bound(f, f + 28, n) - f;
    if (f[k] != n) {puts("NO"); exit(0);}
    int zx = Findzx(u, n);
    rep0(i, sz(G[zx]))
	{
        int v = G[zx][i].X, w = G[zx][i].Y;
       	if(vis[w]) continue;
       	e[v] = w;
        dfs(v, zx);
    }
    gg = -1;
    rep0(i, sz(G[zx]))
	{
        int v = G[zx][i].X, w = G[zx][i].Y;
        if(vis[w]) continue;
        find(v, zx, -1);
        if (gg != -1) break;
    }
    if (gg == -1) {puts("NO"); exit(0);}
    vis[e[gg]] = 1;
   	int x = siz[gg], _zx = zx, _k = k;
    if (x == f[_k - 1]) 
	{
        solve(gg, f[_k - 1]);
        solve(_zx, f[_k - 2]);
    } 
	else 
	{
        solve(gg, f[_k - 2]);
        solve(_zx, f[_k - 1]);
    }
}
 
int main() 
{
    n = read(); 
    f[0] = 1; f[1] = 1;
    rep(i, 2, 27) f[i] = f[i - 1] + f[i - 2];
    rep(i, 1, n - 1)
    {
        int u = read();
        int v = read();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
    }
    solve(1, n);
    puts("YES");
    return 0;
}