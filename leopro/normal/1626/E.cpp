#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout <<  (out) << '\n'; return; }
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
    vector<int> c(n);
    for (int &x: c) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int b = accumulate(c.begin(), c.end(), 0);
    vector<bool> ok(n);
    map<pair<int, int>, int> can;
    vector<int> cntup(n), cntdown(n);
    auto dfs = [&](auto dfs, int cur, int prev) -> void {
        cntdown[cur] = c[cur];
        for (int nxt: g[cur]) {
            if (nxt == prev) continue;
            dfs(dfs, nxt, cur);
            cntdown[cur] += cntdown[nxt];
            can[{cur,nxt}] = cntup[nxt] >= 2;
        }
        cntup[cur] = b - cntdown[cur];
        if (cur != prev) can[{cur,prev}] = cntdown[cur] >= 2;
    };
    dfs(dfs, 0, 0);
    auto go = [&](auto go, int cur) -> void {
        if (ok[cur]) return;
        ok[cur] = true;
        for (int nxt: g[cur]) {
            if (can[{cur, nxt}]) {
                go(go, nxt);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!c[i]) continue;
        go(go, i);
        for (int x: g[i]) {
            go(go, x);
        }
    }
    for (int i = 0; i < n; ++i) cout << ok[i] << ' ';
}