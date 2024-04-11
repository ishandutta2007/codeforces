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

template<typename T>
using pqg = priority_queue<T, vector<T>, greater<>>;
using edge = pair<int, int>;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<string> grid(n);
    for (auto &row: grid) cin >> row;
    auto ok = [&](int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };
    auto idx = [&](int i, int j) { return i * m + j; };
    vector<vector<edge>> g(n * m);
    auto link = [&](int u, int v, int w) {
        g[u].emplace_back(v, w);
    };
    ll INF = 1e18;
    vector<ll> d(n * m, INF);
    pqg<pair<ll, int>> dijkstra;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') continue;
            if (grid[i][j] == '.') {
                d[idx(i, j)] = 0;
                dijkstra.emplace(0, idx(i, j));
            }

            if (ok(i - 1, j) && grid[i - 1][j] == 'D') link(idx(i, j), idx(i - 2, j), q);
            if (ok(i - 1, j) && grid[i - 1][j] == 'L') link(idx(i, j), idx(i - 1, j + 1), p);
            if (ok(i - 1, j) && grid[i - 1][j] == 'R') link(idx(i, j), idx(i - 1, j - 1), p);

            if (ok(i + 1, j) && grid[i + 1][j] == 'U') link(idx(i, j), idx(i + 2, j), q);
            if (ok(i + 1, j) && grid[i + 1][j] == 'L') link(idx(i, j), idx(i + 1, j + 1), p);
            if (ok(i + 1, j) && grid[i + 1][j] == 'R') link(idx(i, j), idx(i + 1, j - 1), p);

            if (ok(i, j + 1) && grid[i][j + 1] == 'L') link(idx(i, j), idx(i, j + 2), q);
            if (ok(i, j + 1) && grid[i][j + 1] == 'U') link(idx(i, j), idx(i + 1, j + 1), p);
            if (ok(i, j + 1) && grid[i][j + 1] == 'D') link(idx(i, j), idx(i - 1, j + 1), p);

            if (ok(i, j - 1) && grid[i][j - 1] == 'R') link(idx(i, j), idx(i, j - 2), q);
            if (ok(i, j - 1) && grid[i][j - 1] == 'U') link(idx(i, j), idx(i + 1, j - 1), p);
            if (ok(i, j - 1) && grid[i][j - 1] == 'D') link(idx(i, j), idx(i - 1, j - 1), p);
        }
    }
    while (!dijkstra.empty()) {
        auto [dist, cur] = dijkstra.top();
        dijkstra.pop();
        if (d[cur] != dist) continue;
        for (auto [nxt, w]: g[cur]) {
            if (d[nxt] > d[cur] + w) {
                d[nxt] = d[cur] + w;
                dijkstra.emplace(d[nxt], nxt);
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ok(i, j + 1)) ans = min(ans, d[idx(i, j)] + d[idx(i, j + 1)]);
            if (ok(i + 1, j)) ans = min(ans, d[idx(i, j)] + d[idx(i + 1, j)]);
        }
    }
    if (ans == INF) answer(-1);
    answer(ans);
}