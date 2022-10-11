#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x, x--;
    for (auto &x : b) cin >> x, x--;
    
    vector<int> freq(n);
    for (auto x : a) freq[x]++;
    int bad = max_element(all(freq)) - freq.begin();

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[a[i]].push_back(b[i]);
    }

    vector<int> used(n);
    used[bad] = 2;
    bool ok = true;

    for (int i = 0; i < n; i++) {
        if (used[i] != 0) continue;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = 1;
            for (auto u : g[v]) {
                if (used[u] == 0) {
                    dfs(u);
                } else if (used[u] == 1) {
                    ok = false;
                }
            }
            used[v] = 2;
        })(i);
    }
    cout << (ok ? "AC" : "WA") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}