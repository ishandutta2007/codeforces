#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;


const int N = 100 * 1000 + 10;
vector<int> g[N];
long long value[N];
long long pl[N];
long long mn[N];
bool u[N];

void dfs(int v)
{
    u[v] = true;

    int kids = 0;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!u[to])
            ++kids;
    }

    if (kids == 0)
    {
        if (value[v] > 0)
        {
            pl[v] = 0;
            mn[v] = value[v];
        }
        else
        {
            pl[v] = -value[v];
            mn[v] = 0;
        }
        return;
    }

    vector<long long> p, m;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (u[to])
            continue;
        dfs(to);
        p.push_back(pl[to]);
        m.push_back(mn[to]);
    }
    sort(p.begin(), p.end());
    sort(m.begin(), m.end());
    pl[v] = p[0];
    mn[v] = m[0];
    for (int i = 1; i < p.size(); ++i)
    {
        pl[v] += p[i] - p[i - 1];
        mn[v] += m[i] - m[i - 1];
    }
    long long cur = value[v] + pl[v] - mn[v];
    if (cur < 0)
        pl[v] -= cur;
    else
        mn[v] += cur;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i)
        cin >> value[i];

    fill(u, u + n, false);
    dfs(0);
    cout << pl[0] + mn[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}