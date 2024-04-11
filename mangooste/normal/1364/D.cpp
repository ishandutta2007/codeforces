#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n, m, k;
vector<vector<int>> G;
vector<int> parent, depth, col;
vector<char> used;
vector<int> t0, t1;
vector<pair<int, int>> maybe;

void dfs_tree(int v) {
    if (col[v] == 0) {
        t0.push_back(v);
    } else {
        t1.push_back(v);
    }
    used[v] = 1;
    for (auto u : G[v]) {
        if (!used[u]) {
            col[u] = col[v] ^ 1;
            dfs_tree(u);
        }
    }
}

void dfs(int v) {
    used[v] = 1;
    for (auto u : G[v]) {
        if (u == parent[v]) {
            continue;
        }
        if (used[u]) {
            maybe.emplace_back(v, u);
        } else {
            depth[u] = depth[v] + 1;
            parent[u] = v;
            dfs(u);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    parent.resize(n);
    parent[0] = 0;
    used.resize(n, 0);
    depth.resize(n, 0);
    col.resize(n, 0);
    if (m == n - 1) {
        dfs_tree(0);
        int sum = accumulate(col.begin(), col.end(), 0);
        cout << "1\n";
        if (sum >= (k + 1) / 2) {
            for (int i = 0; i < (k + 1) / 2; i++) {
                cout << t1[i] + 1 << ' ';
            }
            cout << '\n';
        } else {
            for (int i = 0; i < (k + 1) / 2; i++) {
                cout << t0[i] + 1 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    dfs(0);
    sort(maybe.begin(), maybe.end(), [&](pair<int, int> &a, pair<int, int> &b) {
        int len1 = abs(depth[a.first] - depth[a.second]);
        int len2 = abs(depth[b.first] - depth[b.second]);
        return len1 < len2;
    });
    int v = maybe[0].first, u = maybe[0].second;
    if (depth[v] < depth[u]) {
        swap(u, v);
    }
    vector<int> way;
    while (v != u) {
        way.push_back(v);
        v = parent[v];
    }
    way.push_back(u);
    if (way.size() <= k) {
        cout << "2\n";
        cout << way.size() << '\n';
        for (auto el : way) {
            cout << el + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "1\n";
        for (int i = 0, where = 0; i < (k + 1) / 2; i++, where += 2) {
            cout << way[where] + 1 << ' ';
        }
        cout << '\n';
    }
}