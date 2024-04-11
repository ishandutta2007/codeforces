#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
int mod = 1e9 + 7;
const int N = 3e5+ 100;
vector <pair <int, int> > g[N];
vector <pair <int, int> > g_rev[N];
int vis[N];
int cc[N];
int offset[N];
int ncc = 1;
int loop[N];
vector <int> ord;
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void dfs_fwd(int x)
{
    vis[x] = 1;
    for(auto to : g[x])
    {
        int  y = to.X;
        if(vis[y] != 1)
        {
            dfs_fwd(y);
        }
    }
    ord.push_back(x);
}
void dfs_rev(int x)
{
    vis[x] = 2;
    for(auto to : g_rev[x])
    {
        int y = to.X;
        int l = to.Y;
        if(vis[y] != 2)
        {
            cc[y] = cc[x];
            offset[y] = offset[x] + l;
            dfs_rev(y);
        }
        else if(cc[y] == cc[x])
        {
            loop[cc[x]] = gcd(loop[cc[x]], abs(offset[x] + l - offset[y]));
        }
    }
}
signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i= 0; i < m; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        g[a].push_back({b, l});
        g_rev[b].push_back({a, l});
    }
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs_fwd(i);
        }
    }
    reverse(ord.begin(), ord.end());
    for(auto i : ord)
    {
        if(vis[i] != 2)
        {
            cc[i] = ncc++;
            offset[i] = 0;
            dfs_rev(i);
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int v, s, t;
        cin >> v >> s >> t;
        v--;
        if(s % __gcd(loop[cc[v]], t) == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}