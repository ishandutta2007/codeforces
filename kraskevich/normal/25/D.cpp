#include <iostream>
#include <map>
#include <vector>
using namespace std;

int s = -1, e = -1;
vector<bool> u;
int g[1000][1000];
int n;
vector<int> v1, v2, v3, v4;

void dfs_cycle(int v, int p)
{
    if(s >= 0)
        return;
        
    u[v] = true;
    for(int to = 0; to < n; ++to)
    {
        if(!g[v][to])
            continue;
            
        if(!u[to])
            dfs_cycle(to, v);
        else
            if(to != p)
            {
                s = v;
                e = to;
                return;
            }
    }
}

void dfs(int v)
{
    u[v] = true;
    int to;
    for(int to = 0; to < n; ++to)
    {
        if(!g[v][to])
            continue;
        
        if(!u[to])
            dfs(to);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            g[i][j] = 0;
        
    for(int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[b][a] = g[a][b] = 1;
    }
    
    for(int day = 0;; ++day)
    {
        u.assign(n, false);
        dfs(0);
        
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(u[i]) ++cnt;
        if(cnt == n)
        {
            cout << day << endl;
            break;
        }
        
        u.assign(n, false);
        
        s = -1, e = -1;
        for(int i = 0; i < n; ++i)
            if(s == -1 && !u[i])
                dfs_cycle(i, -1);
            
        u.assign(n, false);
        dfs(s);
        
        for(int i = 0; i < n; ++i)
            if(!u[i])
            {
                g[i][s] = g[s][i] = 1;
                g[s][e] = g[e][s] = 0;
                v1.push_back(s + 1);
                v2.push_back(e + 1);
                v3.push_back(s + 1);
                v4.push_back(i + 1);
                break;
            }
    }
    
    for(int i = 0; i < v1.size(); ++i)
        cout << v1[i] << " " << v2[i] << " " << v3[i] << " " << v4[i] << endl;
    cin >> n;
    
    return 0;
}