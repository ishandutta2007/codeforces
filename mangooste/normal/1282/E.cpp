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
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

inline pair<int, int> mp(int a, int b) {
    if (a > b) swap(a, b);
    return make_pair(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n - 2);
    vector<set<int>> inds(n);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            a[i][j]--;
            inds[a[i][j]].insert(i);
        }
    }

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.emplace(len(inds[i]), i);
    }

    vector<int> q;
    set<pair<int, int>> edges;

    auto myErase = [&](int pos, int id) {
        st.erase({len(inds[pos]), pos});
        inds[pos].erase(id);
        if (len(inds[pos])) st.insert({len(inds[pos]), pos});
    };

    function<void(int)> dfs = [&](int n) {
        auto [ln, v] = *st.begin();
//         dbg("dfs", ln, v);
        if (n == 3) {
            q.emplace_back(*inds[v].begin());
            for (int i = 0; i < 3; i++) {
                for (int j = i + 1; j < 3; j++) {
                    edges.insert(mp(a[*inds[v].begin()][i], a[*inds[v].begin()][j]));
                }
            }
            return;
        }

        assert(ln == 1);
        auto id = *inds[v].begin();
        vector<int> another;
        for (auto x : a[id]) {
            myErase(x, id);
            if (x != v) another.emplace_back(x);
        }
        dfs(n - 1);

        assert(len(another) == 2);
        int a = another[0], b = another[1];
//         dbg("dfs", ln, v);
//        dbg(another);
        assert(edges.find(mp(a, b)) != edges.end());
//         dbg("fine");
        edges.erase(mp(a, b));
        edges.emplace(mp(v, a));
        edges.emplace(mp(v, b));

        q.emplace_back(id);
    };
    dfs(n);
//   dbg("hi");

    vector<vector<int>> g(n);
    for (auto [v, u] : edges) {
        g[v].emplace_back(u);
        g[u].emplace_back(v);
    }
    vector<char> used(n);
    vector<int> que;
    que.emplace_back(0);
    for (int st = 0; st < len(que); st++) {
        int v = que[st];
        used[v] = 1;

        assert(len(g[v]) == 2);
        for (auto u : g[v]) {
            if (used[u]) continue;
            que.emplace_back(u);
            break;
        }
    }

    assert(len(que) == n);
    for (auto x : que) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
    reverse(all(q));
    for (auto x : q) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}