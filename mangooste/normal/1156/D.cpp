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

int n;
vector<vector<pair<int, int>>> G;
vector<char> used;
vector<int> comp_zero, comp_one;

int dfs(int v, int col, vector<int> &comp) {
    used[v] = 1;
    comp.push_back(v);
    int size = 1;
    for (auto [u, type] : G[v]) {
        if (col != type) {
            continue;
        }
        if (!used[u]) {
            size += dfs(u, col, comp);
        }
    }
    return size;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u, col;
        cin >> v >> u >> col;
        v--, u--;
        G[v].emplace_back(u, col);
        G[u].emplace_back(v, col);
    }
    ll ans = 0;
    comp_zero.resize(n);
    used = vector<char>(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            vector<int> cur_comp;
            int cur_size = dfs(i, 0, cur_comp);
            ans += 1ll * cur_size * (cur_size - 1);
            for (auto v : cur_comp) {
                comp_zero[v] = cur_size;
            }
        }
    }
    comp_one.resize(n);
    used = vector<char>(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            vector<int> cur_comp;
            int cur_size = dfs(i, 1, cur_comp);
            ans += 1ll * cur_size * (cur_size - 1);
            for (auto v : cur_comp) {
                comp_one[v] = cur_size;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int cur_zero = 1, cur_one = 1;
        for (auto [u, col] : G[i]) {
            if (col == 0) {
                cur_zero = comp_zero[i];
            } else {
                cur_one = comp_one[i];
            }
        }
        ans += 1ll * (cur_one - 1) * (cur_zero - 1);
    }
    cout << ans << '\n';
}