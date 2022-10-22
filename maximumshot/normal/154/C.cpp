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
const LL base = inf * 10000 + 7; 
const LL p = 239017;

bool solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    vec< vec<int> > g(n);
    vec< pair<int, int> > e; 

    for(int u, v, i(0);i < m;i++)
    {
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back(mp(u, v));
    }
    
    vec<LL> w(n + 1);
    w[0] = 1ll;
    for(int i(1);i <= n;i++) w[i] = (w[i - 1] * p);

    vec<LL> a;

    for(int i(0);i < n;i++)
    {
        LL h = 0;
        for(int j(0);j < (int)g[i].size();j++)
            h = (h + (g[i][j] + 1) * w[g[i][j] + 1]);
        a.push_back(h);
    }

    LL cnt = 0, ans = 0;

    for(int i(0);i < m;i++)
    {
        int u = e[i].first;
        int v = e[i].second;

        LL h1, h2;

        h1 = (a[u] - (v + 1) * w[v + 1]);
        h2 = (a[v] - (u + 1) * w[u + 1]);

        if(h1 == h2) ans++;
    }

    sort(ALL(a));

    cnt = 1;
    for(int i(1);i < n;i++)
    {
        if(a[i] == a[i - 1]) cnt++;
        else ans += cnt * (cnt - 1) / 2, cnt = 1;
    }
    ans += cnt * (cnt - 1) / 2, cnt = 1;

    cout << ans << '\n';

    return true;
}
  
int main()
{
    //while(solve());
    solve();
  
    return 0;
}