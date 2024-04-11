#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
  
using namespace std;
  
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector
#define go(x, y) q.push(mp((x), (y))), ans[(x)][(y)] = 1;
  
typedef long long LL;
typedef long double LD;
  
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 30) + 1;    

int n;
vec< vec< pair<int, LL> > > g;
vec< LL > h, dp, weight;
vec< pair<int, int> > e;
LL sum = 0;

LL dfs(int v, int par = -1, int H = 0)
{
    h[v] = H;
    dp[v] = 1;
    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i].first;
        LL w = g[v][i].second;
        if(to == par) continue;
        dp[v] += dfs(to, v, H + 1);
        sum += w * dp[to] * ((LL)n - dp[to]);
    }

    return dp[v];
}

bool solve()
{
    scanf("%d", &n);

    g.resize(n);
    h.resize(n, 0);
    dp.resize(n, 0);

    for(int u, v, l, i(0);i < n - 1;i++)
    {
        scanf("%d %d %d", &u, &v, &l);
        u--, v--;
        e.push_back(mp(u, v));
        weight.push_back(l);
        g[u].push_back(mp(v, l));
        g[v].push_back(mp(u, l));
    }

    dfs(0);

    int q, id, u, v;
    LL neww;
    scanf("%d", &q);

    while(q--)
    {
        scanf("%d %I64d", &id, &neww);  
        id--;
        u = e[id].first;
        v = e[id].second;

        if(h[u] > h[v]) swap(u, v);

        // u -> v

        sum += dp[v] * ((LL)n - dp[v]) * (neww - weight[id]);
        weight[id] = neww;

        LD ans = sum;
        ans = ans * 6.0 / ((LD)n * ((LD)n - 1));

        printf("%.10Lf\n", ans);
    }

    return true;    
}
  
int main()
{
    //while(solve());
    solve();
  
    return 0;
}