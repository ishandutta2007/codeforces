#include <iostream>
#include <vector>
using namespace std;

const int N = 2 * 100 * 1000;
vector<int> g[N];
vector<int> tin(N), tout(N);
vector<bool> w(N, false);
int timer = 0;
int u[N][30];
vector<int> cnt(N, 0);
vector<int> s(N, 0);

void dfs1(int v, int p)
{
     w[v] = true;
     tin[v] = timer++;
     u[v][0] = p;
     for(int i = 1; i < 30; ++i)
             u[v][i] = u[u[v][i - 1]][i - 1];
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(!w[to])
                       dfs1(to, v);
     }
     tout[v] = timer++;
}

bool is_anc(int a, int b)
{
     return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
{
    if(is_anc(a, b))
                 return a;
    if(is_anc(b, a))
                 return b;
    for(int i = 29; i >= 0; --i)
            if(!is_anc(u[a][i], b))
                                a = u[a][i];
    return u[a][0];
}

void dfs2(int v)
{
     int curs = 0;
     w[v] = true;
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(!w[to])
             {
                       dfs2(to);
                       curs += s[to];
             }
     }
     s[v] = curs + cnt[v];
}

void upd(int a, int b)
{
     int v = lca(a, b);
     ++cnt[a];
     ++cnt[b];
     --cnt[v];
     --cnt[v];
}

int ans(int u, int v)
{
    if(tin[u] > tin[v])
              swap(u, v);
    return s[v];
}

int st[N], fin[N];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; ++i)
    {
            int u, v;
            cin >> u >> v;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
            st[i] = u;
            fin[i] = v;
    }
    
    dfs1(0, 0);
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; ++i)
    {
            int u, v;
            cin >> u >> v;
            --u, --v;
            upd(u, v);
    }
    
    w.assign(n, false);
    dfs2(0);
    
    for(int i = 0; i < n - 1; ++i)
            cout << ans(st[i], fin[i]) << " ";
    
    cin >> n;
    return 0;
}