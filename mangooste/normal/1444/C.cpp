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

int n, m, k;
vector<int> group;
vector<vector<int>> g;
vector<pair<int, int>> edges;

vector<vector<int>> groups;

vector<char> good;
vector<int> col;

int curCompId;
vector<int> compId;

bool ok;
vector<int> curComp;

ll ans = 0;

vector<vector<pair<int, int>>> chkg;
bool bad;
vector<int> curColor;

void dfs(int v) {
    curComp.push_back(v);
    for (auto u : g[v]) {
        if (col[u] == -1) {
            col[u] = col[v] ^ 1;
            dfs(u);
        } else if (col[u] != (col[v] ^ 1)) {
            ok = false;
        }
    }
}

inline pair<int, int> get(pair<int, int> edge) {
    return pair<int, int>{group[edge.first], group[edge.second]};
}

void dfsChk(int v) {
    for (auto [u, type] : chkg[v]) {
        if (curColor[u] == -1) {
            curColor[u] = curColor[v] ^ type;
            dfsChk(u);
        } else if (curColor[u] != (curColor[v] ^ type)) {
            bad = true;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    group.resize(n);
    groups.resize(k);
    forn (i, 0, n) {
        cin >> group[i];
        group[i]--;
        groups[group[i]].push_back(i);
    }

    g.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        if (group[v] == group[u]) {
            g[v].push_back(u);
            g[u].push_back(v);
        } else {
            if (group[v] > group[u]) swap(v, u);
            edges.emplace_back(v, u);
        }
    }

    good.resize(k, 1);
    col.resize(n, -1);
    curCompId = 0;
    compId.resize(n, -1);

    forn (i, 0, k) {
        for (auto v : groups[i]) {
            if (col[v] != -1) continue;
            col[v] = 0;
            curComp.clear();
            ok = true;
            dfs(v);

            forn (i, 0, len(curComp)) compId[curComp[i]] = curCompId;
            curCompId++;
            good[i] &= ok;
        }
    }

    sort(all(edges), [&](pair<int, int> a, pair<int, int> b) {
        return get(a) < get(b);
    });

    int nGood = accumulate(all(good), 0);
    ans = 1ll * nGood * (nGood - 1) / 2;

    curColor.resize(n);
    chkg.resize(n);

    forn (i, 0, len(edges)) {
        int j = i;
        while (j < len(edges) && get(edges[i]) == get(edges[j])) j++;

        auto [group1, group2] = get(edges[i]);
        if (good[group1] && good[group2]) {
            forn (k, i, j) {
                auto [v, u] = edges[k];
                chkg[compId[v]].clear();
                chkg[compId[u]].clear();
            }

            vector<int> vers;
            forn (k, i, j) {
                auto [v, u] = edges[k];
                vers.push_back(compId[v]);
                vers.push_back(compId[u]);

                int type = col[v] != col[u];
                chkg[compId[v]].emplace_back(compId[u], type);
                chkg[compId[u]].emplace_back(compId[v], type);
            }

            for (auto v : vers) curColor[v] = -1;
            bad = false;
            for (auto v : vers) {
                if (curColor[v] == -1) {
                    curColor[v] = 0;
                    dfsChk(v);
                    if (bad) break;
                }
            }
            ans -= bad;
        }

        i = j - 1;
    }

    assert(ans >= 0);
    cout << ans << '\n';
}