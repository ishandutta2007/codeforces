#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7ll;    
const double pi = acos(-1.0);

using namespace std;

int Abs(int x) {return (x >= 0?x : -x);}

const int LOG = 21;

int n, m;

vec< vec<int> > g;
vec<int> h, dp, par[LOG];
vec<bool> used;

void dfs(int v, int p = -1, int H = 0)
{
    h[v] = H;
    used[v] = 1;
    par[0][v] = p;

    for(int i(1);i < LOG;i++)
    {
        int x = par[i - 1][v];
        if(x == -1) break;
        par[i][v] = par[i - 1][x];
    }

    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i];

        if(!used[to])
        {
            dfs(to, v, H + 1);
            dp[v] += dp[to] + 1;
        }
    }
}

int lca(int a, int b)
{
    if(h[a] > h[b]) swap(a, b);

    for(int i(LOG - 1);i >= 0;i--)
    {
        int x = par[i][b];
        if(x == -1 || h[x] < h[a]) continue;
        b = x;
    }

    for(int i(LOG - 1);i >= 0;i--)
    {
        if(par[i][a] == -1 || par[i][b] == -1 || par[i][a] == par[i][b]) continue;
        a = par[i][a];
        b = par[i][b];
    }

    if(a != b) a = par[0][a];

    return a;
}

bool solve()
{
    cin >> n;

    g.resize(n);
    h.resize(n);
    dp.resize(n);
    used.assign(n, false);

    for(int i(0);i < LOG;i++) par[i].resize(n, -1);
    
    for(int u, v, i(0);i < n - 1;i++)
    {
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    cin >> m;

    for(int i(0);i < m;i++)
    {
        int a, b;

        cin >> a >> b;
        a--, b--;

        if(a == b) 
        {
            cout << n << '\n';
            continue;
        }

        int x = lca(a, b);

        //cout << x << '\n';

        int d1, d2, d;

        d1 = h[a] - h[x];
        d2 = h[b] - h[x];
        d = d1 + d2;

        if(d % 2) {puts("0"); continue;}

        if(d1 == d2)
        {
            int ans = n, y, newh;

            newh = h[x] + 1;

            if(a != x)
            {
                y = a;
            
                for(int j(LOG - 1);j >= 0;j--)
                {
                    int p = par[j][y];
                    if(p == -1 || h[p] < newh) continue;
                    y = p;
                }
                
                ans -= (dp[y] + 1);
            }

            if(b != x)
            {
                y = b;

                for(int j(LOG - 1);j >= 0;j--)
                {
                    int p = par[j][y];
                    if(p == -1 || h[p] < newh) continue;
                    y = p;
                }

                ans -= (dp[y] + 1);
            }

            cout << ans << '\n';

            continue;
        }

        if(h[a] >= h[b]) swap(a, b);

        int newh = h[b] - d / 2 + 1, y;
        y = b;

        for(int j(LOG - 1);j >= 0;j--)
        {
            int p = par[j][y];
            if(p == -1 || h[p] < newh) continue;
            y = p;
        }

        cout << dp[par[0][y]] - dp[y] << '\n';
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}