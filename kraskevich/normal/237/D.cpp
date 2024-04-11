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
 
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define REP(i, l, r) for (int i = l; i < r; ++i)
#define REPDOWN(i, r, l) for (int i = r; i >= l; --i)
#define FORN for (int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define PB push_back
 
typedef long long i64;

const int N = 100 * 1000 + 1;
vector<int> g[N];
vector<pii> ans;
vector<pii> edge;
vector<bool> u(N, false);

int dfs(int v)
{
    u[v] = true;
    
    vector<int> now;
    
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (u[to])
            continue;
        
        int col = dfs(to);
        ans.push_back(pii(v, to));
        if (col >= 0)
            edge.push_back(pii(ans.size() - 1, col));
        now.push_back(ans.size() - 1);
    }
    
    for (int i = 1; i < now.size(); ++i)
        edge.push_back(pii(now[i], now[0]));
    
    return (now.size() > 0 ? now[0] : -1);
}

int main()
{
    int n;
    scanf("%d", & n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        scanf("%d%d", & u, & v);
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    
    dfs(0);
    
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", 2, ans[i].F + 1, ans[i].S + 1);
    for (int i = 0; i < edge.size(); ++i)
        printf("%d %d\n", edge[i].F + 1, edge[i].S + 1);
    
    return 0;
}