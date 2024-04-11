#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>

using namespace std;


#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w
#define ALL(x) x.begin(), x.end()

const int N = 3000;

bool dir[N][N], u[N];
vector<int> g[N];
int n, dp[N], res = 1000 * 1000 * 1000;

void dfs1(int v)
{
    u[v] = true;
    dp[v] = 0;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!u[to])
        {
            dfs1(to);
            dp[v] += dp[to];
            if (!dir[v][to])
                ++dp[v];
        }
    }
}

int path[N];
int szp;
int now;

void dfs2(int v, int sumdp, int s0, int s1, int h, int cnt0)
{
    u[v] = true;
    sumdp += dp[v];
    
    
    while (h < szp && s1 > s0)
    {
        if (path[h] == 0)
            --s0, ++cnt0;
        else
            --s1;
        ++h;
    }
    
    if (v != now)
        res = min(res, cnt0 + s1 + sumdp);
        
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        
        if (u[to])
            continue;
            
        path[szp++] = (dir[v][to] ? 1 : 0);
        
        sumdp -= dp[to];
        if (!dir[v][to])
            --sumdp;
        
        if (dir[v][to])
            ++s1;
        else
            ++s0;
            
        dfs2(to, sumdp, s0, s1, h, cnt0);
        
        szp--;
        if (dir[v][to])
            --s1;
        else
            --s0;
        sumdp += dp[to];
        if (!dir[v][to])
            ++sumdp;
    }
}

int main()
{
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j)
            dir[i][j] = false;
            
    scanf("%d", & n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        scanf("%d%d", & a, & b);
        --a;
        --b;
        dir[a][b] = true;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            u[j] = false;
        szp = 0;
        now = i;
        dfs1(i);
        for (int j = 0; j < n; ++j)
            u[j] = false;
        dfs2(i, 0, 0, 0, 0, 0);
    }
    
    if (n == 1)
        res = 0;
    printf("%d", res);
    
    
    return 0;
}