#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

struct Query {
    int type;
    int v;

    Query() {}
    Query(int type, int v) : type(type), v(v) {}
};

int n, m, q;
vector<int> p;
vector<pair<int, int>> edges;
vector<int> when;
vector<Query> queries;

vector<int> par;
vector<int> sz;
vector<int> each;

vector<set<int>> g;
vector<int> color;
vector<priority_queue<int>> values;

vector<char> deleted;

inline int getPar(int v) {
    return par[v] == v ? v : par[v] = getPar(par[v]);
}

void dfs(int v, int par, int other, int newColor) {
    if (!deleted[v]) values[newColor].push(p[v]);
    color[v] = newColor;
    for (auto u : g[v]) {
        if (u == par) continue;
        dfs(u, v, other, newColor);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    p.resize(n);
    forn (i, 0, n) cin >> p[i];

    edges.resize(m);
    forn (i, 0, m) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--, edges[i].second--;
    }

    when.resize(m, q);
    forn (i, 0, q) {
        int type, v;
        cin >> type >> v;
        v--;
        queries.push_back(Query(type, v));
        if (type == 2) when[v] = i;
    }

    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int v, int u) {
        return when[v] > when[u];
    });

    par.resize(n);
    iota(all(par), 0);
    sz.resize(n, 1);
    g.resize(n);

    vector<int> best(m, -1);
    for (auto i : ord) {
        auto [v, u] = edges[i];
        int vv = getPar(v);
        int uu = getPar(u);
        if (vv == uu) continue;

        if (sz[vv] < sz[uu]) swap(vv, uu), swap(v, u);
        par[uu] = vv;
        sz[vv] += sz[uu];

        best[i] = u;
        g[v].insert(u);
        g[u].insert(v);
    }

    color.resize(n, -1);
    values.resize(n);

    int free = 0;
    each.resize(n, -1);
    forn (i, 0, n) {
        int pr = getPar(i);
        if (each[pr] == -1) each[pr] = free++;
        color[i] = each[pr];
        values[color[i]].push(p[i]);
    }

    vector<int> which(n);
    forn (i, 0, n) which[p[i] - 1] = i;

    deleted.resize(n);
    for (auto [type, v] : queries) {
        if (type == 1) {
            int col = color[v];
            while (len(values[col])) {
                int v = which[values[col].top() - 1];
                if (color[v] != col || deleted[v]) values[col].pop();
                else break;
            }
            if (len(values[col])) {
                int ans = values[col].top();
                values[col].pop();
                cout << ans << '\n';
                deleted[which[ans - 1]] = 1;
            } else {
                cout << "0\n";
            }
        } else if (type == 2 && best[v] != -1) {
            int who = best[v];
            int other = (edges[v].first ^ edges[v].second ^ who);

            g[who].erase(other);
            g[other].erase(who);
            dfs(who, who, other, free++);
        }
    }
}