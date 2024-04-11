#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bool> good(1 << n);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        good[x] = true;
    }

    vector<int> ord;
    ord.reserve(1 << n);
    vector<bool> used(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        if (used[i]) continue;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            for (int i = 0; i < n; i++) {
                if (v >> i & 1) {
                    int u = v ^ (1 << i);
                    if (!used[u]) dfs(u);
                }
            }
            if (good[v]) {
                int u = ((1 << n) - 1) ^ v;
                if (!used[u]) dfs(u);
            }
            ord.push_back(v);
        })(i);
    }
    reverse(all(ord));

    int cur = 0;
    vector<int> scc_num(1 << n, -1);
    for (auto i : ord) {
        if (scc_num[i] != -1) continue;
        
        y_combinator([&](auto dfs, int v) -> void {
            scc_num[v] = cur;
            for (int i = 0; i < n; i++) {
                if (!(v >> i & 1)) {
                    int u = v ^ (1 << i);
                    if (scc_num[u] == -1) dfs(u);
                }
            }
            int u = ((1 << n) - 1) ^ v;
            if (good[u] && scc_num[u] == -1) dfs(u);
        })(i);

        cur++;
    }

    vector<bool> any_good(cur);
    for (int i = 0; i < (1 << n); i++) {
        if (good[i]) any_good[scc_num[i]] = true;
    }
    cout << count(all(any_good), true) << '\n';
}