// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

int n, m;
vec< vec<pii> > g;
vec<bool> used;

void dfs(int v, int col)
{
    used[v] = 1;

    for(int i(0);i < (int)g[v].size();i++)
    {
        int to, w;

        to = g[v][i].first;
        w = g[v][i].second;

        if(w != col) continue;

        if(!used[to]) dfs(to, col);
    }
}

bool solve()
{
    cin >> n >> m;
    
    g.resize(n);

    for(int u, v, w, i(0);i < m;i++)
    {
        cin >> u >> v >> w;

        u--, v--;

        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }

    int q, ans, a, b;

    cin >> q;
    
    while(q--)
    {
        ans = 0;

        cin >> a >> b;

        a--, b--;

        for(int i(1);i <= m;i++)
        {
            used.assign(n, false);

            dfs(a, i);

            ans += used[b];
        }

        cout << ans << '\n';
    }

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}