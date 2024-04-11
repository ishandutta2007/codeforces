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

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<array<int, 2>> edges(n);
    vector<vector<int>> g(2 * n);
    for (int i = 0; i < n; i++) {
        for (int j : {0, 1}) {
            cin >> edges[i][j];
            edges[i][j]--;
            g[edges[i][j]].push_back(i);
        }
    }

    auto another = [&](int id, int v) {
        return edges[id][0] ^ edges[id][1] ^ v;
    };

    array<string, 2> first, second;
    array<vector<int>, 2> a;

    vector<bool> used_v(2 * n), used_e(n);
    for (int root = 0; root < 2 * n; root++) {
        if (used_v[root]) continue;
        vector<int> ord;

        y_combinator([&](auto dfs, int v) -> void {
            ord.push_back(v);
            if (used_v[v]) return;

            used_v[v] = true;
            for (auto id : g[v]) {
                if (used_e[id]) continue;
                used_e[id] = true;
                int u = another(id, v);
                dfs(u);
                ord.push_back(v);
            }
        })(root);

        assert(ord[0] == ord.back() && len(ord) % 2);
        ord.pop_back();
        int cur_size = len(ord) / 2;
        if (cur_size == 1) {
            cout << "-1\n";
            return 0;
        }

        for (int i = 0; i < cur_size; i++) {
            a[0].push_back(ord[i]);
            a[1].push_back(ord.end()[-1 - i]);
        }

        int size_before = len(first[0]);
        first[0] += string(cur_size, 'U');
        first[1] += string(cur_size, 'D');
        second[0] += string(cur_size, 'U');
        second[1] += string(cur_size, 'D');

        for (int i = 0; i + 1 < cur_size; i += 2) {
            for (int j : {0, 1}) {
                first[j][size_before + i] = 'L';
                first[j][size_before + i + 1] = 'R';
            }
        }
        for (int i = 1; i + 1 < cur_size; i += 2) {
            for (int j : {0, 1}) {
                second[j][size_before + i] = 'L';
                second[j][size_before + i + 1] = 'R';
            }
        }
    }

    cout << "2 " << n << '\n';
    for (auto &v : a) {
        for (int i = 0; i < n; i++) {
            cout << v[i] + 1 << " \n"[i == n - 1];
        }
    }
    for (auto grid : {first, second}) {
        cout << '\n' << grid[0] << '\n' << grid[1] << '\n';
    }
}