#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back

vector<vector<int> > g;
bool bridge[2000][2000];
vector<int> tin, tmin;
vector<bool> u;
int timer = 0;

void dfs(int v, int anc)
{
     u[v] = true;
     tmin[v] = tin[v] = timer++;
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(to == anc)
                   continue;
             if(u[to])
             {
                      tmin[v] = min(tmin[v], tin[to]);
                      continue;
             }
             dfs(to, v);
             tmin[v] = min(tmin[v], tmin[to]);
             if(tmin[to] > tin[v])
                         bridge[to][v] = bridge[v][to] = true;
     }
}

vector<int> p;

void dfs2(int v, int anc)
{
     p[v] = anc;
     u[v] = true;
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(!u[to])
                       dfs2(to, v);
     }
}
             
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, k;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) 
                    bridge[i][j] = false;
    
    g.resize(n);
    u.assign(n, false);
    tin.resize(n);
    tmin.resize(n);
    
    for(int i = 0; i < m; ++i)
    {
            int a, b;
            cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
    }
    
     for(int i = 0; i < n; ++i)
            if(!u[i])
                     dfs(i, -1);

    cin >> k;
    
    int s[k], e[k];
    
    for(int i = 0; i < k; ++i)
            cin >> s[i] >> e[i];
    
    for(int i = 0; i < k; ++i)
    {
            --s[i], --e[i];
            u.assign(n, false);
            p.assign(n, -1);
            dfs2(s[i], -1);
            vector<int> path;
            for(int v = e[i]; v != s[i]; v = p[v])
                    path.push_back(v);
            path.push_back(s[i]);
            int ans = 0;
            for(int j = 1; j < path.size(); ++j)
                    ans += (bridge[path[j]][path[j - 1]] ? 1 : 0);
            
            cout << ans << endl;
    }
    
    cin >> n;
            
    return 0;
}