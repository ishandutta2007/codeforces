#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
const int mod = 998244353;
const int N = 310;
int n;
vector <int> g[N];
int dp[N][N][2];
int dep[N];
int ndp[N][2];
int d;
void dfs(int v, int p = -1)
{
    dep[v] = 0;
    dp[v][0][0] = 1;
    dp[v][0][1] = 1;
    for(int it = 0; it < sz(g[v]); it++)
    {
        int to = g[v][it];
        if(to == p)
        {
            continue;
        }
        dfs(to, v);
        int ndep = min(max(dep[v], dep[to] + 1), d);
        for(int i = 0; i <= ndep; i++)
        {
            for(int t = 0; t < 2; t++)
            {
                ndp[i][t] = 0;
            }
        }
        for(int x = 0; x <= dep[v]; x++)
        {
            for(int xt = 0; xt < 2; xt++)
            {
                if(xt && x >= d)
                {
                    continue;
                }
                int curx = dp[v][x][xt];
                for(int y = 0; y <= dep[to]; y++)
                {
                    for(int yt = 0; yt < 2; yt++)
                    {
                        if(yt && y > d)
                        {
                            continue;
                        }
                        int cury = dp[to][y][yt];
                        int z, zt;
                        if(xt == yt)
                        {
                            zt = xt;
                            if(zt)
                            {
                                z = max(x, y + 1);
                            }
                            else
                            {
                                z = min(x, y + 1);
                            }
                        }
                        else{
                            int dist = x + y + 1;
                            if(dist <= d)
                            {
                                zt = 0;
                                z = (xt == 0 ? x : y + 1);
                            }
                            else
                            {
                                zt = 1;
                                z = (xt == 1 ? x : y + 1);
                            }
                        }
                        z = min(z, ndep);
                        ndp[z][zt] = (ndp[z][zt] + curx * cury % mod) % mod;
                    }
                }
            }
        }
        for(int i = 0; i <= ndep; i++)
        {
            for(int t = 0; t < 2; t++)
            {
                dp[v][i][t] = ndp[i][t];
            }
        }
        dep[v] = ndep;
    }
}
signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int p = 1;
    for(int i = 0; i < n; i++)
    {
        p = p * 2 % mod;
    }
    int res = 0;
    for(d = 1; d < n; d++)
    {
        dfs(0, -1);
        int cur = p;
        for(int i = 0; i <= dep[0]; i++)
        {
            cur = (cur + mod - dp[0][i][0]) % mod;
        }
        res = (res + cur) % mod;
    }
    for(int i = 0; i < n; i++)
    {
        res = res * ((mod + 1) / 2) % mod;
    }
    cout << res;
    return 0;
}