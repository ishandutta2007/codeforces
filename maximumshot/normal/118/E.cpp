#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int n, m, comp = 0;
vec< set<int> > f, g, gt;
vec<bool> used;
set< pair<int, int> > ans;

void dfs(int v)
{
    used[v] = 1;

    for(set<int>::iterator i = f[v].begin();i != f[v].end();i++)
    {
        int to = *i;
        g[v].insert(to), gt[to].insert(v); 
        f[to].erase(v);
        if(!used[to]) dfs(to);
    }
}

void dfs2(int v)
{
    used[v] = 1;
    comp++;
    for(set<int>::iterator i = gt[v].begin();i != gt[v].end();i++)
    {
        int to = *i;
        if(!used[to]) dfs2(to);
    }
}

bool solve()
{
    cin >> n >> m;

    f.resize(n);
    g.resize(n);
    gt.resize(n);
    used.assign(n, false);

    for(int u, v, i(0);i < m;i++)
    {
        scanf("%d %d", &u, &v);
        u--, v--;
        f[u].insert(v);
        f[v].insert(u);
    }

    dfs(0);

    used.assign(n, false);
    
    dfs2(0);

    if(comp != n) {puts("0\n"); return true;}

    for(int i(0);i < n;i++) for(set<int>::iterator j = g[i].begin();j != g[i].end();j++) printf("%d %d\n", i + 1, *j + 1);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}