#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;
const int N = 100 * 1000 + 10;

int n, m, d;
bool u[N];
bool good[N];
vector<int> g[N];
int hh[N];
int lo[N];

void dfs1(int v)
{
    u[v] = true;
    if (good[v])
        hh[v] = 0;
    else
        hh[v] = -INF;
    for (int to: g[v])
    {
        if (u[to])
            continue;
        dfs1(to);
        hh[v] = max(hh[v], hh[to] + 1);
    }
}

void dfs2(int v, int best)
{
    u[v] = true;
    if (good[v])
        lo[v] = max(best, 0);
    else
        lo[v] = best;
    multiset<int> s;
    for (auto to: g[v])
    {
        if (u[to])
            continue;
        s.insert(hh[to]);
    }
    for (auto to: g[v])
    {
        if (u[to])
            continue;
        int mx = lo[v];
        s.erase(s.find(hh[to]));
        auto it = s.end();
        if (it != s.begin())
        {
            --it;
            mx = max(mx, *it + 1);
        }
        dfs2(to, mx + 1);
        s.insert(hh[to]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        freopen("out.cpp", "w", stdout);
    #endif

    cin >> n >> m >> d;
    fill(good, good + n, false);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        --x;
        good[x] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(u, u + n, 0);
    dfs1(0);
    fill(u, u + n, 0);
    dfs2(0, -INF);
    vector<int> res;
    for (int i = 0; i < n; i++)
        if (hh[i] <= d && lo[i] <= d)
            res.push_back(d);
    cout << res.size();

    return 0;
}