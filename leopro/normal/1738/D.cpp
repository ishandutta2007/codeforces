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
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int &x: b) cin >> x;
    vector<vector<int>> g(n + 2);
    for (int i = 0; i < n; ++i) {
        g[b[i]].push_back(i + 1);
    }
    assert(g[0].empty() != g[n + 1].empty());
    int low = 0, high = n + 1;
    vector<int> a;
    auto go = [&](auto go, int cur, bool greater) -> void {
        if (greater) high = min(high, cur); else low = max(low, cur);
        a.push_back(cur);
        sort(g[cur].begin(), g[cur].end(), [&g](auto u, auto v) { return g[u].size() < g[v].size(); });
        for (int nxt: g[cur]) go(go, nxt, !greater);
    };
    if (g[n + 1].empty()) {
        go(go, 0, false);
    } else {
        go(go, n + 1, true);
    }
    cout << low << '\n';
    for (int x: a) if (0 < x && x <= n) cout << x << ' ';
    cout << '\n';
}