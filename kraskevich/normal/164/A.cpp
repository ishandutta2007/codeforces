#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > g, gr;
vector<bool> u1, u2;
vector<int> type;

void dfs1(int v, int p)
{
     u1[v] = true;
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(!u1[to])
                        dfs1(to, v);
     }
}

void dfs2(int v)
{
     u2[v] = true;
     if(type[v] == 1)
                return;
     for(int i = 0; i < gr[v].size(); ++i)
     {
             int to = gr[v][i];
             if(!u2[to])
                        dfs2(to);
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    type.resize(n);
    u1.assign(n, 0);
    u2.assign(n, 0);
    
    for(int i = 0; i < n; ++i)
            cin >> type[i];
            
    for(int i = 0; i < m; ++i)
    {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            g[a].push_back(b);
            gr[b].push_back(a);
    }
    
    for(int i = 0; i < n; ++i)
            if(!u1[i] && type[i] == 1)
                      dfs1(i, -1);
    for(int i = 0; i < n; ++i)
            if(!u2[i] && type[i] == 2)
                      dfs2(i);
    
    for(int i = 0; i < n; ++i)
            cout << (u1[i] && u2[i] ? 1 : 0) << endl;
    
    return 0;
}