#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << (ans) << '\n'; return;}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> t(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> d(n);
    auto dfs = [&](auto dfs, int cur, int prev) -> void {
        for (int next: t[cur]) {
            if (next == prev) continue;
            d[next] = d[cur] + 1;
            dfs(dfs, next, cur);
        }
    };
    dfs(dfs, 0, 0);
    for (int i = 0; i < n; ++i) {
        cout << (int)t[i].size() * (d[i] % 2 == 0 ? 1 : -1) << ' ';
    }
    cout << '\n';
}