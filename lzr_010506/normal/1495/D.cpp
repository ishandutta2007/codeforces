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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 405;
const int mod = 998244353;
int n, m, f[N], g[N][N], e[N][N], d[N][N];
vi G[N];

int main() 
{
    n = read(); 
    m = read();
    rep(i, 1, n)
    	rep(j, 1, n)
    		if(i != j) d[i][j] = INF;
    rep0(i, m)
    {
    	int u = read();
    	int v = read();
    	G[u].pb(v);
    	G[v].pb(u);
    	e[u][v] = e[v][u] = 1;
    	d[u][v] = d[v][u] = 1;
    }
    rep(k, 1, n)
    	rep(i, 1, n)
    		rep(j, 1, n)
    			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    rep(u, 1, n)
    {
    	rep(v, 1, n)
    	{
            int ans = 1;
            if (u != v) 
            {
                int num = 0;
                rep(i, 1, n) 
                {
                    if (d[u][i] == 0) continue;
                    if (d[v][i] == 0) continue;
                    int res = 0;
                    if (d[u][v] == d[u][i] + d[v][i]) num ++;
                    else 
                    {
                    	rep0(j, sz(G[i]))
						{
							int to = G[i][j];
                            if (d[u][to] == d[u][i] - 1 && d[v][to] == d[v][i] - 1) 
                                res ++;
						}
                        ans = 1ll * ans * res % mod;
                	}
                }
                if (num != d[u][v] - 1) ans = 0;
            }
            else 
            {
            	rep(i, 1, n)
            	{
                    if (d[u][i] == 0) continue; 
                    int res = 0;
                    rep(j, 1, n) if (e[i][j] && d[u][j] == d[u][i] - 1) res ++;
                    ans = 1ll * ans * res % mod;
                }
            } 
            
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}