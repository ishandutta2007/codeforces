#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second

const int N = 5001;
vector<short> f(N, -1);
vector<short> g[N];
vector<short> p(N, -1);
vector<bool> u(N, false);
int best = 0, num;

void dfs(int v)
{
     u[v] = true;
     if(!v)
     {
           f[v] = 0;
           return;
     }
     for(int i = 0; i < g[v].size(); ++i)
     {
             int to = g[v][i];
             if(!u[to])
                       dfs(to);
             if(f[to] > 0 || f[to] == 0 && to == 0)
             {
                      if(f[to] + 1 > f[v])
                               p[v] = to;
                      f[v] = max((int)f[v], f[to] + 1);
                      if(f[v] > best)
                              best = f[v], num = v;
             }
     }
}   

vector<pii> wh;

void go(int v)
{
     if(!v)
           return;
     go(p[v]);
     cout << v << " ";
}        

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, w, h;
    cin >> n >> w >> h;
    
    wh.push_back(pii(w, h));
    
    for(int i = 0; i < n; ++i)
    {
            cin >> w >> h;
            wh.push_back(pii(w, h));
    }
    
    ++n;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    if(wh[i].F < wh[j].F && wh[i].S < wh[j].S)
                               g[j].push_back(i);
    
    for(int i = n - 1; i > 0; --i)              
            if(!u[i])
                     dfs(i);
    
    cout << best << endl;
    go(num);
    
    return 0;
}