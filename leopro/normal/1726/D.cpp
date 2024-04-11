#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }
#define answerExit(answer) { cout << (answer) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e.emplace_back(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> seen(n);
    set<pair<int, int>> back;
    vector<int> d(n), p(n);
    auto dfs = [&](auto dfs, int cur, int prev) -> bool {
        if (seen[cur]) return false;
        seen[cur] = true;
        for (int nxt: g[cur]) {
            if (nxt == prev) continue;
            if (!seen[nxt]) {
                d[nxt] = d[cur] + 1;
                p[nxt] = cur;
                dfs(dfs, nxt, cur);
            } else {
                back.emplace(cur, nxt);
            }
        }
        return true;
    };
    dfs(dfs, 0, 0);
    set<int> vs;
    for (auto &[u, v]: back) vs.insert(u);
    for (auto &[u, v]: back) vs.insert(v);
    auto r = [&](pair<int, int> a) { return pair{a.second, a.first}; };
    if (vs.size() > 3 || back.size() < 3) {
        for (int j = 0; j < m; ++j) cout << (back.contains(e[j]) || back.contains(r(e[j])));
        cout << '\n';
    } else {
        int top = *vs.begin();
        for (int x: vs) if (d[x] < d[top]) top = x;
        for (auto[u, v]: back) {
            if (abs(d[u] - d[v]) == 1)continue;
            if (u == top) swap(u, v);
            if (v == top) {
                auto a = back;
                a.erase(find(a.begin(), a.end(), pair{u, v}));
                a.erase(find(a.begin(), a.end(), pair{v, u}));
                while (p[u] != top) u = p[u];
                a.emplace(u, p[u]);
                for (int j = 0; j < m; ++j) cout << (a.contains(e[j]) || a.contains(r(e[j])));
                cout << '\n';
                return;
            }
        }
    }
}