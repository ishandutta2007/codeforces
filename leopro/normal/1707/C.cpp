#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

struct dsu {
    vector<int> parent, size;

    dsu(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    int get(int x) { return parent[x] == x ? x : parent[x] = get(parent[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        size[y] += size[x];
        parent[x] = y;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[x, y]: edges) {
        cin >> x >> y;
        --x, --y;
    }
    dsu dsu(n);
    vector<vector<int>> t(n);
    vector<pair<int, int>> b;
    for (auto[x, y]: edges) {
        if (dsu.unite(x, y)) {
            t[x].push_back(y);
            t[y].push_back(x);
        } else {
            b.emplace_back(x, y);
        }
    }
    int time = 0;
    vector<int> tin(n), tout(n), p(n), d(n);
    auto dfs = [&](auto dfs, int cur, int prev) -> void {
        tin[cur] = time++;
        for (int next: t[cur]) {
            if (next == prev) {
                p[cur] = next;
                continue;
            }
            d[next] = d[cur] + 1;
            dfs(dfs, next, cur);
        }
        tout[cur] = time++;
    };
    dfs(dfs, 0, 0);
    vector<vector<int>> up(__lg(n) + 1, vector<int>(n));
    for (int i = 0; i < n; ++i) up[0][i] = p[i];
    for (int lvl = 1; lvl < up.size(); ++lvl) {
        for (int i = 0; i < n; ++i) up[lvl][i] = up[lvl - 1][up[lvl - 1][i]];
    }
    auto lca = [&](int x, int y) -> pair<int, int> {
        for (int l = up.size() - 1; l >= 0; --l) if (d[up[l][x]] > d[y]) x = up[l][x];
        for (int l = up.size() - 1; l >= 0; --l) if (d[up[l][y]] > d[x]) y = up[l][y];
        if (d[x] + 1 == d[y]) {
            if (p[y] == x) return {x, y};
            y = p[y];
        }
        if (d[x] == d[y] + 1) {
            if (p[x] == y) return {x, y};
            x = p[x];
        }
        for (int l = up.size() - 1; l >= 0; --l) {
            if (up[l][x] != up[l][y]) {
                x = up[l][x];
                y = up[l][y];
            }
        }
        return {x, y};
    };
    vector<int> good(time + 1);
    int best = 0;
    for (auto[x, y]: b) {
        auto[lx, ly] = lca(x, y);
        if (p[lx] == ly) {
            swap(lx, ly);
            swap(x, y);
        }
        if (p[ly] == lx) {
            good[tin[y]]++;
            good[tout[y]]--;
            good[0]++;
            good[tin[ly]]--;
            good[tout[ly]]++;
            good[time]--;
            best++;
        } else if (p[ly] == p[lx]) {
            good[tin[y]]++;
            good[tout[y]]--;
            good[tin[x]]++;
            good[tout[x]]--;
            best++;
        } else {
            assert(false);
        }
    }
    for (int i = 1; i < good.size(); ++i) good[i] += good[i - 1];
    for (int i = 0; i < n; ++i) cout << (good[tin[i]] == best);
    cout << '\n';
}