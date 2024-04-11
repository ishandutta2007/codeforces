#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

struct disjoin_set_union {
    int components;
    std::vector<int> parent, rank;

    disjoin_set_union(int n = 0) : components(n), parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int size() const {
        return rank.size();
    }

    void set_default() {
        components = size();
        std::fill(rank.begin(), rank.end(), 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) == 0 ? v : parent[v] = root(parent[v]);
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        components--;
        return true;
    }

    bool connected(int v, int u) {
        return root(v) == root(u);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), inv_p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i], p[i]--;
        inv_p[p[i]] = i;
    }

    disjoin_set_union dsu(n);
    auto ans = inv_p;
    for (int i = 0; i < n; i++) {
        dsu.unite(i, inv_p[i]);
    }

    for (int x = 0; x < n - 1;) {
        int y = x + 1;
        while (y < n && !dsu.connected(x, y)) {
            dsu.unite(x, y);
            swap(ans[x], ans[y]);
            y++;
        }
        x = y;
    }
    assert(dsu.components == 1);

    vector<int> ord{0};
    for (int i = ans[0]; i; i = ans[i]) {
        ord.push_back(i);
    }

    assert(len(ord) == n);
    for (int i = 0; i < n; i++) {
        cout << ord[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}