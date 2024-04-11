#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

struct strongly_connected_component {
    int n;
    std::vector<std::vector<int>> g;

    strongly_connected_component(int n = 0) : n(n), g(n) {}

    int size() const {
        return n;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].push_back(to);
    }

    std::vector<int> scc() const {
        std::vector<int> num(n, -1), low(n), scc(n, -1), st;
        int v_num = 0, scc_num = 0;

        std::function<void(int)> tarjan = [&](int v) {
            st.push_back(v);
            num[v] = low[v] = v_num++;
            for (auto u : g[v]) 
                if (num[u] == -1) {
                    tarjan(u);
                    low[v] = std::min(low[v], low[u]);
                } else if (scc[u] == -1) {
                    low[v] = std::min(low[v], num[u]);
                }

            if (num[v] == low[v]) {
                while (true) {
                    int u = st.back();
                    st.pop_back();
                    scc[u] = scc_num;
                    if (u == v)
                        break;
                }
                scc_num++;
            }
        };

        for (int v = 0; v < n; v++)
            if (num[v] == -1)
                tarjan(v);

        assert(st.empty());
        for (auto &x : scc)
            x = scc_num - 1 - x;

        return scc;
    }
};

struct two_sat {
    int n;
    strongly_connected_component g;

    two_sat(int n = 0) : n(n), g(n << 1) {}

    int size() const {
        return n;
    }

    void add(int v, bool value_v) {
        assert(0 <= v && v < n);
        g.add((v << 1) ^ value_v ^ 1, (v << 1) ^ value_v);
    }

    void add(int v, bool value_v, int u, bool value_u) {
        assert(0 <= v && v < n && 0 <= u && u < n);
        g.add((v << 1) ^ value_v ^ 1, (u << 1) ^ value_u);
        g.add((u << 1) ^ value_u ^ 1, (v << 1) ^ value_v);
    }

    std::vector<bool> solve() const {
        const std::vector<int> scc = g.scc();
        std::vector<bool> solution(n);
        for (int i = 0; i < n; i++) {
            if (scc[i << 1] == scc[i << 1 | 1])
                return std::vector<bool>();

            solution[i] = scc[i << 1] < scc[i << 1 | 1];
        }
        return solution;
    }

    bool any() const {
        const std::vector<int> scc = g.scc();
        for (int i = 0; i < n; i++)
            if (scc[i << 1] == scc[i << 1 | 1])
                return false;

        return true;
    }
};

void solve(int test_num) {
    int n, m, k;
    cin >> n >> m >> k;

    two_sat g((n + 1) * (k + 1));
    g.add(0, true);
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            g.add((i + 1) * (k + 1) - 1, true);
        } else {
            g.add((i + 1) * (k + 1) - 1, false);
            for (int j = 0; j <= k; j++) {
                g.add(i * (k + 1) + j, false, (i + 1) * (k + 1) + j, true);
            }
        }
        for (int j = 1; j <= k; j++) {
            g.add(i * (k + 1) + j, false, i * (k + 1) + (j - 1), true);
        }
    }

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, value;
            cin >> pos >> value;
            pos--;
            g.add(pos * (k + 1) + value - 1, false, pos * (k + 1) + value, true);
        } else {
            int i, j, x;
            cin >> i >> j >> x;
            i--, j--;

            if (type == 2) {
                for (int v2 = 1; v2 <= k; v2++) {
                    if (v2 > x) {
                        g.add(j * (k + 1) + v2 - 1, false);
                        continue;
                    }
                    int v1 = min(k + 1, x - v2 + 1);
                    g.add(j * (k + 1) + v2 - 1, false, i * (k + 1) + v1 - 1, false);
                }
            } else {
                for (int v1 = 1; v1 <= k; v1++) {
                    if (x - v1 >= k + 1) {
                        g.add(i * (k + 1) + v1 - 1, true);
                        continue;
                    }
                    int v2 = max(1, x - v1 + 1);
                    g.add(i * (k + 1) + v1 - 1, true, j * (k + 1) + v2 - 1, true);
                }
            }
        }
    }

    auto sol = g.solve();
    if (sol.empty()) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        int x = k;
        while (!sol[i * (k + 1) + x - 1]) x--;
        cout << x << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}