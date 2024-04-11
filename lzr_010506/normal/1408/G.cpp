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
const int mod = 998244353;

inline int add(int x, int y) 
{
    return x + y >= mod ? x + y - mod : x + y;
}

const int N = 1505;

int n, m, Num, F[N * 2], tms, vis[N * 2], tms2, vis2[N * 2], id[N * 2], gg[N * 2];
int siz[N * 2], f[N * 2][N];
bool can[N * 2];
vector<int> e[N * 2];

struct Edge 
{
    int u, v, w;
} edg[N * N];

bool operator <(const Edge &i, const Edge &j) 
{
    return i.w < j.w;
}

int find(int u) 
{
	if(F[u] == u) return u;
	return F[u] = find(F[u]);
}

void dfs1(int u) 
{
    siz[u] = u <= n;
    rep0(i, sz(e[u]))
    {
    	int v = e[u][i];
        dfs1(v);
        siz[u] += siz[v];
        gg[u] += gg[v];
    }
    can[u] = gg[u] + siz[u] - 1 == siz[u] * (siz[u] - 1) / 2;
}

void dfs2(int u) 
{
    siz[u] = u <= n;
    f[u][0] = 1;
    rep0(hh, sz(e[u]))
    {
    	int v = e[u][hh];
        dfs2(v);
        rrep(i, siz[u] + siz[v], 0)
        {
            int res = 0;
            for (int j = max(0, i - siz[u]); j <= siz[v] && j <= i; j++) 
                res = add(res, 1ll * f[u][i - j] * f[v][j] % mod);
            
            f[u][i] = res;
        }
        siz[u] += siz[v];
    }
    f[u][0] = 0;
    if (can[u]) { f[u][1] = add(f[u][1], 1); }
}

int main() 
{
    n = read();
    rep(u, 1, n)
    	rep(v, 1, n)
    	{
            int w = read();
            if (u < v) { edg[m ++] = (Edge) {u, v, w}; }
        }
    
    sort(edg, edg + m); 
    Num = n;
    rep(u, 1, n * 2)
        F[u] = u;
    
    for (int i = 0, j; i < m; i = j) 
    {
        vector<int> p;
        tms++;
        for (j = i; j < m && edg[i].w == edg[j].w; j++) 
        {
            int u = edg[j].u, v = edg[j].v;
            u = find(u); 
            v = find(v);
            if (u == v) { gg[u] ++; continue; }
            F[u] = v;
            if (vis[u] != tms) p.pb(u); 
            if (vis[v] != tms)  p.pb(v); 
        }
        tms++; tms2++;
        for (auto u : p) 
        {
            if (vis[u] == tms) continue; 
            vis[u] = tms;
            if (vis2[find(u)] != tms2) 
            {
                vis2[find(u)] = tms2;
                id[find(u)] = ++Num;
                id[Num] = Num;
            }
        }
        tms++;
        for (auto u : p) 
    
            if (vis[u] != tms) 
            {
            	vis[u] = tms;
            	e[id[find(u)]].pb(u);
        	}
            
        tms++;
        for (auto u : p) 
        {
            if (vis[u] != tms)
            {
	            vis[u] = tms;
	            int x = find(u);
	            F[x] = id[x];
	        }	
        }
    }
    dfs1(Num); dfs2(Num);
    rep(i, 1, n)
        printf("%d ", f[Num][i]);
    
    return 0;
}