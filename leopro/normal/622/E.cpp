#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto dfs, int cur, int prev, int d, vector<int> &v) -> void {
        if (g[cur].size() == 1) {
            v.push_back(d);
        }
        for (int next: g[cur]) {
            if (next == prev) continue;
            dfs(dfs, next, cur, d + 1, v);
        }
    };
    int ans = 0;
    for (int next: g[0]) {
        vector<int> v;
        dfs(dfs, next, 0, 1, v);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            if (i && v[i] <= v[i - 1]) v[i] = v[i - 1] + 1;
        }
        ans = max(ans, v.back());
    }
    cout << ans << '\n';
}