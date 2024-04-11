#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

int n, r1, r2;
vec< vec<int> > g;
vec<int> ans;
vec<bool> used;

void dfs(int v, int p)
{
    ans[v] = p;
    used[v] = 1;

    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i];
        if(!used[to]) dfs(to, v);
    }
}

bool solve()
{
    cin >> n >> r1 >> r2;

    r1--, r2--;

    g.resize(n);
    ans.resize(n);
    used.assign(n, false);

    for(int x, i(0);i < n;i++)
    {
        if(i == r1) continue;
        cin >> x;
        x--;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(r2, r2);

    for(int i(0);i < n;i++)
    {
        if(i == r2) continue;
        cout << ans[i] + 1 << ' ';
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}