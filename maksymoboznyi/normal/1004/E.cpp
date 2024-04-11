#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
const int LOG = 25;

int n, k, up[N][LOG], par[N], dep[N], max_dist[N], sad[N], kol_sad[N], used[N], dist[N];
vector<pair<int, int> > g[N];

void dfs_lca(int v, int p = 0) {
    par[v] = p;
    dep[v] = dep[p] + 1;
    max_dist[v] = 0;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i].first != p)
            dfs_lca(g[v][i].first, v), max_dist[v] = max(max_dist[v], max_dist[g[v][i].first] + g[v][i].second);
}

void dfs_make_sad(int v, int d, int back_edge = 0) {
    used[v] = 1;
    if (back_edge + max_dist[v] > d)
        sad[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i].first])
            dfs_make_sad(g[v][i].first, d, g[v][i].second), kol_sad[v] += kol_sad[g[v][i].first] + sad[g[v][i].first];
}

bool can(vector<int> way, int d) {
    if (way.size() > k)
        return 0;
    for (int i = 1; i <= n; i++)
        dist[i] = 1000000001;
    set<pair<int, int> > q;
    for (int i = 0; i < way.size(); i++)
        q.insert({0, way[i]}), dist[way[i]] = 0;
    while (!q.empty()) {
        int v = q.begin() -> second, de = q.begin()->first;
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); i++)
            if (dist[g[v][i].first] > de + g[v][i].second) {
                q.erase({dist[g[v][i].first], g[v][i].first});
                dist[g[v][i].first] = de + g[v][i].second;
                q.insert({dist[g[v][i].first], g[v][i].first});
            }
    }
    for (int i = 1; i <= n; i++)
        if (dist[i] > d)
            return 0;
    return 1;
}

bool check(int dist) {
    for (int i = 1; i <= n; i++)
        sad[i] = 0, kol_sad[i] = 0, used[i] = 0;
    dfs_make_sad(1, dist);
    vector<int> sad_kids;
    for (int i = 1; i <= n; i++)
        if (sad[i] && kol_sad[i] == 0)
            sad_kids.pb(i);
   // for (int i = 1; i <= n; i++)
     //   cout << sad[i] << ' ' << kol_sad[i] << endl;
    if (sad_kids.size() > 2)
        return 0;
    if (sad_kids.size() == 2) {
        vector<int> way;
        int u = sad_kids[0], v = sad_kids[1];
        while (u != v)
            if (dep[u] > dep[v])
                way.pb(u), u = par[u];
            else
                way.pb(v), v = par[v];
        way.pb(u);
        return can(way, dist);
    }
    if (sad_kids.size() == 0)
        return 1;
    if (sad_kids.size() == 1) {
        vector<int> way;
        int v = sad_kids[0];
        while (v != 0 && way.size() < k)
            way.pb(v), v = par[v];
        return can(way, dist);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dfs_lca(1);
//    cout << check(4);

    int l = -1, r = 1000000001;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << r;
    return 0;
}