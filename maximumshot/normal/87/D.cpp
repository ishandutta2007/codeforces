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
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = 1ll << 32;
const LD eps = 1e-11;
 
int n;
LL sum;
vec< pair<int, int> > e, mas;
vec< vec< pair<int, int> > > g;
vec<int> par, size, used;
vec<LL> cnt;

int find(int x)
{
    return (x == par[x]?x : par[x] = find(par[x]));
}

void merge(int u, int v)
{
    int pu, pv;
    pu = find(u);
    pv = find(v);
    if(size[pu] < size[pv]) swap(pu, pv);
    par[pv] = pu, size[pu] += size[pv];
}

void read()
{
    scanf("%d", &n);

    for(int i(0);i < n - 1;i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        e.push_back(mp(u, v));
        mas.push_back(mp(w, i));
    }

    sort(ALL(mas));

    par.resize(n, -1);
    size.resize(n, 1);
    for(int i(0);i < n;i++) par[i] = i;
    g.clear();
    g.resize(n);
    cnt.resize(n, 0);
    used.resize(n, 0);
}

int dfs(int v, int par = -1)
{
    int ans = size[v];
    used[v] = 1;
    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i].first;
        int id = g[v][i].second;
        if(to == par) continue;
        int tmp = dfs(to, v);
        cnt[id] = 2ll * (LL)tmp * LL(sum - tmp);
        ans += tmp;
    }

    return ans;
}

int go(int v, int par = -1)
{
    int ans = size[v];
    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i].first;
        if(to == par) continue;
        ans += go(to, v);
    }

    return ans;
}

bool solve()
{
    read();
    for(int i(0);i < n - 1;i++)
    {
        int w;
        w = mas[i].first;
        set<int> s;
        s.clear();
        int j = i;
        while(j < n - 1 && mas[j].first == w) 
        {
            int id = mas[j].second;
            s.insert(find(e[id].first));
            s.insert(find(e[id].second));
            j++;
        }

        for(auto it : s) used[it] = 0, g[it].clear();

        for(int z(i);z < j;z++)
        {
            int id = mas[z].second;
            int x, y;
            x = e[id].first;  x = find(x);
            y = e[id].second; y = find(y);
            g[x].push_back(mp(y, id));
            g[y].push_back(mp(x, id));
        }

        for(auto it : s) sort(ALL(g[it])), g[it].resize(unique(ALL(g[it])) - g[it].begin());

        for(auto it : s)
        {
            if(used[it]) continue;
            sum = go(it);
            dfs(it);
        }

        for(int z(i);z < j;z++)
        {
            int id = mas[z].second;
            int u, v;
            u = e[id].first;  
            v = e[id].second;
            merge(u, v);
        }

        i = j - 1;
    }

    vec< pair<LL, int> > ans;

    for(int i(0);i < n - 1;i++) ans.push_back(mp(cnt[i], -i));

    sort(ALL(ans));
    reverse(ALL(ans));

    int C = 0;
    for(int i(0);i < n - 1;i++) if(ans[i].first == ans.front().first) C++;

    printf("%I64d %d\n", ans.front().first, C);
    
    for(int i(0);i < C;i++) printf("%d ", -ans[i].second + 1);
    puts("");

    return true; 
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}