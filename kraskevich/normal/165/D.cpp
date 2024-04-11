#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second

struct fenw
{
       vector<int> t;
       void init(int n)
       {
            t.assign(n, 0);
       }
       void upd(int i, int val)
       {
            for(; i < t.size(); i = (i | (i + 1)))
                  t[i] += val;
       }
       int getS(int i)
       {
           int res = 0;
           for(; i >= 0; i = (i & (i + 1)) - 1)
                 res += t[i];
           return res;
       }
       int sum(int l, int r)
       {
           if(l > r)
                return 0;
           return getS(r) - (l ? getS(l - 1) : 0);
       }
};

const int N = 500000;
vector<int> deg(N, 0);
vector<int> comp(N, -1);
vector<int> h(N, 0);
vector<int> g[N];
fenw f[N];
int mx;

void dfs(int v, int c, int hh)
{
     comp[v] = c;
     h[v] = hh;
     mx = max(mx, hh);
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(comp[to] == -1)
                         dfs(to, c, hh + 1);
     }
}

int root;

int ans(int v, int u)
{
    if(h[v] > h[u])
            swap(u, v);
    if(v == root || comp[v] == comp[u])
         return (f[comp[u]].sum(h[v] + 1, h[u]) == 0 ? h[u] - h[v] : -1);
    else
        return (ans(v, root) >= 0 && ans(u, root) >= 0 ? ans(v, root) + ans(u, root) : -1);
}

void upd(int u, int v, int t)
{
     if(h[u] < h[v])
             swap(u, v);
     f[comp[u]].upd(h[u], t == 2 ? 1 : -1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int a[n], b[n];
    for(int i = 0; i < n - 1; ++i)
    {
            cin >> a[i] >> b[i];
            --a[i];
            --b[i];
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
            deg[a[i]]++;
            deg[b[i]]++;
    }
    
    int t = 0;
    for(int i = 0; i < n; ++i)
            if(deg[i] > deg[t])
                      t = i;
    
    h[t] = 0;
    comp[t] = 0;
    root = t;
    int c = 0;
    for(int i = 0; i < g[t].size(); ++i)
    {
            mx = 0;
            dfs(g[t][i], c++, 1);
            f[i].init(mx + 2);
    } 
            
    int m;
    cin >> m;
    
    for(int i = 0; i < m; ++i)
    {
           int type;
           cin >> type;
           if(type == 3)
           {
                int u, v;
                cin >> u >> v;
                --u, --v;
                cout << ans(u, v) << endl;
           }
           else
           {
               int id;
               cin >> id;
               --id;
               upd(a[id], b[id], type);
           }
    }
    
    cin >> n;
    
    return 0;
}