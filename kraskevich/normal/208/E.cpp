#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

const int N = 100 * 1000;
vector<int> g[N];
vector<int> h[N];
vector<int> tin(N);
vector<int> tout(N);
vector<bool> u(N, false);
vector<int> hh(N);
int timer = 0;

void dfs(int v, int curh)
{
    u[v] = true;
    tin[v] = timer++;
    h[curh].push_back(v);
    hh[v] = curh;
    
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!u[to])
            dfs(to, curh + 1);
    }
    
    tout[v] = timer++;
}

int getCnt(int mn, int mx, int curh)
{    
    if (!h[curh].size())
        return 0;
        
    int l = 0, r = (int)h[curh].size() - 1;
    
    while (l < r)
    {
        int m = (l + r) / 2;
        if (tin[h[curh][m]] < mn)
            l = m + 1;
        else
            r = m;
    }
    if (tin[h[curh][l]] < mn)
        ++l;
    
    int left = l;
    l = 0;
    r = (int)h[curh].size() - 1;
    
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (tin[h[curh][m]] > mx)
            r = m - 1;
        else
            l = m;
    }
    if (tin[h[curh][r]] > mx)
        --r;
    
    int right = r;
    
    return max(0, right - left + 1);
}

int getPos(int t, int curh)
{
    if (curh < 0)
        return -1;
    
    if (!h[curh].size())
        return -1;
    
    int l = 0, r = (int)h[curh].size() - 1;
    
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (tin[h[curh][m]] > t)
            r = m - 1;
        else
            l = m;
    }
    
    if (tout[h[curh][l]] < t)
        return -1;
    else
        return h[curh][l];
}

int getAns(int v, int p)
{
    int anc = getPos(tin[v], hh[v] - p);
    
    if (anc == -1)
        return 0;
    else
        return getCnt(tin[anc], tout[anc], hh[v]) - 1;
}
    
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    vector<bool> root(n, false);
    
    for (int i = 0; i < n; ++i)
    {
        int v;
        
        cin >> v;
        
        if (!v)
        {
            root[i] = true;
            continue;
        }
        
        --v;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    
    
    for (int i = 0; i < n; ++i)
        if (root[i])
            dfs(i, 0);
            
            
            
    
    int m;
    
    cin >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int v, p;
        
        cin >> v >> p;
        
        --v;
        cout << getAns(v, p) << endl;
    }

    return 0;
}