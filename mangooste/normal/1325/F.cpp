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

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n, m, need = 0;
vector<vector<int>> G;
vector<char> used;
vector<int> dep, parent;

void dfs(int v) {
    used[v] = 1;
    for (auto u : G[v]) {
        if (u == parent[v]) {
            continue;
        }
        if (used[u]) {
            int delta = dep[v] - dep[u] + 1;
            if (delta >= need) {
                vector<int> way;
                while (v != u) {
                    way.push_back(v);
                    v = parent[v];
                }
                way.push_back(u);
                cout << "2\n" << delta << '\n';
                for (auto el : way) {
                    cout << el + 1 << ' ';
                }
                cout << '\n';
                exit(0);
            }
        } else {
            parent[u] = v;
            dep[u] = dep[v] + 1;
            dfs(u);
        }
    }
}

void Main() {
    cin >> n >> m;
    while (need * need < n) {
        need++;
    }
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    used.assign(n, 0);
    dep.assign(n, 0);
    parent.assign(n, 0);
    dfs(0);
    vector<vector<int>> comps(need);
    for (int i = 0; i < n; i++) {
        comps[dep[i] % (need - 1)].push_back(i);
    }
    int where_mx = 0;
    for (int i = 1; i < need; i++) {
        if (comps[where_mx].size() < comps[i].size()) {
            where_mx = i;
        }
    }
    cout << "1\n";
    assert((int)comps[where_mx].size() >= need);
    for (int i = 0; i < need; i++) {
        cout << comps[where_mx][i] + 1 << ' ';
    }
    cout << '\n';
}