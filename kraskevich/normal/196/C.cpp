#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1500;
vector<int> g[N];
vector<int> ans(N);
vector<char> u(N, false);
vector<int> sz(N, 0);

struct point
{
    int x, y, id;
    point(int xx = 0, int yy = 0, int ii = 0)
    {
        x = xx;
        y = yy;
        id = ii;
    }
    point operator - (point & p)
    {
        return point(x - p.x, y - p.y, id);
    }
    point operator + (point & p)
    {
        return point(x + p.x, y + p.y, id);
    }
    long long operator * (point & p)
    {
        return (long long)x * p.y - (long long)y * p.x;
    }
};

bool cmp(point a, point b)
{
    return a * b < 0;
}

void dfs1(int v)
{
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if(!sz[to])
        {
            dfs1(to);
            sz[v] += sz[to];
        }
    }
}

void dfs2(int v, vector<point> p)
{   
    u[v] = true;
    
    int j = 0;
    for(int i = 1; i < p.size(); ++i)
        if(p[i].x < p[j].x || p[i].x == p[j].x && p[i].y < p[j].y)
            j = i;
    swap(p[0], p[j]);
    ans[p[0].id] = v + 1;
    
    vector<point> vv;
    for(int i = 1; i < p.size(); ++i)
        vv.push_back(p[i] - p[0]);
    sort(vv.begin(), vv.end(), cmp);
    
    int cur = 0;
    
    for(int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if(u[to])
            continue;
        
        vector<point> curp;
        for(int j = cur; j < cur + sz[to]; ++j)
            curp.push_back(vv[j] + p[0]);          
             
        cur += sz[to];
        
        dfs2(to, curp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    
    vector<point> p(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    
    dfs1(0);
    dfs2(0, p);
    
    for(int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    
    cin >> n;
    
    return 0;
}