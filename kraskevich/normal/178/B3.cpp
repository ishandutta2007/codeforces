#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int> > g;
vector<int> tin, tmin;
vector<int> col;
int timer = 0, color = 0;
stack<int> vrtx;
vector<char> u;

void paint(int v)
{
     color++;
     while(vrtx.top() != v)
     {
                      col[vrtx.top()] = color;
                      vrtx.pop();
     }
     vrtx.pop();
     col[v] = color;
}

void dfs1(int v, int p)
{
     u[v] = true;
     vrtx.push(v);
     tin[v] = tmin[v] = timer++;
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(to != p)
             {
                 if(u[to])
                          tmin[v] = min(tmin[v], tin[to]);
                 else
                 {
                     dfs1(to, v);
                     tmin[v] = min(tmin[v], tmin[to]);
                     if(tmin[to] > tin[v])  
                                 paint(to);
                 }
             }
     }
     if(p == -1)
     {
          col[v] = 0;
          while(!vrtx.empty())
          {
                              col[vrtx.top()] = 0;
                              vrtx.pop();
          }
     }
}

vector<vector<int> > anc;
int ln;
vector<int> tout;
vector<int> h;

void init(int n)
{
     timer = 0;
     tin.resize(n);
     tout.resize(n);
     g.resize(n);
     h.resize(n);
     u.assign(n, false);
     for(int i = 0; i < n; ++i)
             g[i].clear();
     
     ln = 0;
     while((1 << ln) <= n)
              ++ln;
     ++ln;
     
     anc.assign(n, vector<int> (ln));
}

void dfs2(int v, int p, int H)
{
     h[v] = H;
     tin[v] = timer++;
     u[v] = true;
     anc[v][0] = p;
     for(int i = 1; i < ln; ++i)
             anc[v][i] = anc[anc[v][i - 1]][i - 1];
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(!u[to])
                       dfs2(to, v, H + 1);
     }
     tout[v] = timer++;
}

bool is_lca(int a, int b)
{
     return tin[b] >= tin[a] && tout[b] <= tout[a];
}

int lca(int a, int b)
{
    if(is_lca(a, b))
                return a;
    if(is_lca(b, a))
                return b;
    for(int i = ln - 1; i >= 0; --i)
            if(!is_lca(anc[a][i], b))
                                 a = anc[a][i];
    return anc[a][0];
}

int main()
{
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    u.assign(n, false);
    g.resize(n);
    tin.resize(n);
    tmin.resize(n);
    timer = 0;
    col.resize(n);
    int a[m], b[m];
    
    for(int i = 0; i < m; ++i)
    {
            scanf("%d%d", &a[i], &b[i]);
            
            --a[i], --b[i];
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
    }
    
    dfs1(0, -1);
    
    int maxC = color + 1;
    
    init(maxC);
    for(int i = 0; i < m; ++i)
    {
            int c1 = col[a[i]], c2 = col[b[i]];
            if(c1 != c2)
            {
                  g[c1].push_back(c2);
                  g[c2].push_back(c1);
            }
    }
    dfs2(0, 0, 0);
    
    int k;
    
    cin >> k;
    
    for(int i = 0; i < k; ++i)
    {
            int s, e;
            
            scanf("%d%d", &s, &e);
            
            --s, --e;
            
            printf("%d\n", h[col[s]] + h[col[e]] - 2 * h[lca(col[s], col[e])]);
    }
                       
    return 0;
}