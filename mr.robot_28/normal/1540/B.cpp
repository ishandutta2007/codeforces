#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int N = 300;
const int mod = 1e9 + 7;
vector <int> g[N];
int used[N];
int tin[N], tout[N];
int timer = 0;
int up[N];
int cnk[N][N];
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b %2 == 0)
    {
        int t = power(a, b / 2);
        return 1LL * t * t % mod;
    }
    return 1LL * a * power(a, b - 1) % mod;
}
void dfs(int v, int p = -1)
{
    tin[v] = timer++;
    for(auto to : g[v])
    {
        if(to != p)
        {
            up[to] = v;
            dfs(to, v);
        }
    }
    tout[v] = timer++;
}
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
    while(!pred(a, b))
    {
        a = up[a];
    }
    return a;
}
int cnt[N][N];
int f = 0;
int dist[N][N];
void dfs2(int st, int v, int p = -1, int d = 0)
{
    dist[st][v] = d;
    for(auto to : g[v])
    {
        if(p != to)
        {
            dfs2(st, to, v, d + 1);
        }
    }
}
void dfs1(int v)
{
    f++;
    for(auto to : g[v])
    {
        if(!used[to])
        {
            used[to] = 1;
            dfs1(to);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        dfs2(i, i);
    }
    cnk[0][0] = 1;
    for(int i = 1; i < N; i++)
    {
        cnk[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int t = 0; t < n; t++)
            {
                used[t] = 0;
            }
            int k = lca(i, j);
            for(int t = 0; t < n; t++)
            {
                if(pred(t, i) && pred(k, t) || pred(t, j) && pred(k, t))
                {
                    used[t] = 1;
                }
            }
            for(int t = 0; t < n; t++)
            {
                if(pred(t, i) && pred(k, t) || pred(t, j) && pred(k, t))
                {
                    f = 0;
                    dfs1(t);
                    int a = dist[t][j];
                    int b = dist[t][i];
                    if(b != 0)
                    {
             //           cout << i << " " << j << "\n";
               //         cout << a << "  " << b << " " << f << "\n";
                        cnt[a][b - 1] += f;
                    }
                }
            }
        }
    }
    int inv2 = (mod + 1) / 2;
    int invn = power(n, mod - 2);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            cnt[i][j] += cnt[i][j + 1];
            if(j == 0)
            {
                ans = (ans + 1LL * power(inv2, i) * cnt[i][j]) % mod;
            }
            else
            {
                ans = (ans + 1LL * power(inv2, i + j) * cnk[i + j - 1][j] % mod * cnt[i][j]) % mod;
            }
        }
    }
    cout << 1LL * ans * invn % mod;
    return 0;
}