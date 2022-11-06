#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define REP(i,a) for(int i = 0; i < (a); i ++)
#define INF 999999999
#define vi vector<int>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n, m;
vector<pii> G[100010];
int cnt = 0;
int sz[100010];
bool vis[100010];
ll pw[100010], ny[100010];

ll modinv(int a, int b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1)
	{
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

void dfs(int x, int fa)
{
    cnt ++;
    sz[x] = 1;
    int nn = G[x].size();
    REP(i, nn)
    {
        int to = G[x][i].X;
        if(to == fa) continue;
        if(vis[to]) continue;
        dfs(to, x);
        sz[x] += sz[to];
    }
}
int fz(int x, int fa)
{
    bool flag = true;
    int now = -1;
   	int nn = G[x].size();
    REP(i, nn)
    {
        int to = G[x][i].X;
        if(to == fa) continue;
        if(vis[to]) continue;
        if(sz[to] > cnt / 2) flag = false;
        if(now == -1 || sz[to] > sz[now]) now = to;
    }
    if(flag) return x;
    else return fz(now, x);
}
vi G1[100000];
ll ans = 0;
map<ll, ll> up, down, tot;
vector<map<ll, ll> > ve;
void dfs1(int x, int fa, int dep, int pt, int val)
{
    up[x] = (up[fa] + (pw[dep - 1] * val) % m) % m;
    down[x] = ((10 * down[fa]) % m + val) % m;
    tot[up[x]] ++;
    ve[pt][up[x]] ++;
    int nn = G[x].size();
    REP(i, nn)
    {
        int to = G[x][i].X;
        if(to != fa  && !vis[to]) dfs1(to, x, dep + 1, pt, G[x][i].Y);
    }
}

void calans(int x, int fa, int dep, int pt)
{
    ll dp = down[x];
    ll now = ((((-dp) % m + m) % m) * ny[dep]) % m;
    ans += tot[now] - ve[pt][now];
    int nn = G[x].size();
    REP(i, nn)
    {
        int to = G[x][i].X;
        if(to != fa && !vis[to]) calans(to, x, dep + 1, pt);
    }
}
void solve(int x, int fa)
{
    up.clear();
    down.clear();
    tot.clear();
    ve.clear();
    up[x] = down[x] = 0;
    int nn = G[x].size();
    ve.resize(nn);
    REP(i, nn)
    {
        int to = G[x][i].X;
        if(to != fa && !vis[to])
            dfs1(to, x, 1, i, G[x][i].Y);
    }
    tot[0] ++;
    REP(i, nn)
    {
        int to = G[x][i].X;
        if(to != fa && !vis[to])
            calans(to, x, 1, i);
    }
    ans += tot[0] - 1;
}
int Doit(int x)
{
    cnt = 0;
    dfs(x,-1);
    int now = fz(x, -1);
    vis[now] = true;
    solve(now,-1);
    int nn = G[now].size();
    REP(i, nn)
    {
        int to = G[now][i].X;
        if(!vis[to])
        {
            int nxt = Doit(to);
            G1[now].pb(nxt);
            G1[nxt].pb(now);
        }
    }
}

int main()
{
	n = read();
	m = read();
    REP(i, n - 1)
    {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }
    pw[0] = 1;
    rep(i, 1, n)
    {
        pw[i] = pw[i - 1] * 10;
        pw[i] %= m;
    }
    rep(i, 0, n - 1)
        ny[i] = modinv((int)pw[i], m);

    int rt = Doit(0);
    cout << ans << endl;
    return 0;
}