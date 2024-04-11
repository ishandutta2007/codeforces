#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct restriction {
    int other, type;

    restriction(int other, int type) : other(other), type(type) {}
};

#define answer(ans) {cout << (ans) << endl; return;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<restriction>> g(n);
    for (int i = 0; i < m; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        --u, --v;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
    }
    vector<int> dir(n), x(n);
    vector<vector<int>> toLeft(n);
    auto dfs = [&](auto dfs, int cur, int d) -> bool {
        if (dir[cur] == -d) return false;
        if (dir[cur] == d) return true;
        dir[cur] = d;
        for (auto[nxt, type]: g[cur]) {
            if (!dfs(dfs, nxt, -d)) return false;
            if ((type == 1) == (d == 1)) toLeft[cur].push_back(nxt);
        }
        return true;
    };
    vector<bool> seen(n, false);
    int curX = 0;
    auto topSort = [&](auto topSort, int cur) {
        if (seen[cur]) return;
        seen[cur] = true;
        for (int nxt: toLeft[cur]) {
            topSort(topSort, nxt);
        }
        x[cur] = curX++;
    };
    for (int i = 0; i < n; ++i) {
        if (dir[i]) continue;
        if (!dfs(dfs, i, 1)) answer("NO");
    }
    for (int i = 0; i < n; ++i) {
        topSort(topSort, i);
    }
    for (int u = 0; u < n; ++u) {
        for (int v: toLeft[u]) {
            if (x[v] > x[u]) answer("NO")
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << "L R"[dir[i] + 1] << ' ' << x[i] << '\n';
    }

}