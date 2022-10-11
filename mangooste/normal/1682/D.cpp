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
    string s;
    cin >> n >> s;
    if (count(all(s), '1') % 2 || count(all(s), '0') == n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<pair<int, int>> edges;

    int shift = 0;
    while (s[(shift + n - 1) % n] == '0') shift++;
    rotate(s.begin(), shift + all(s));
    
    array<vector<int>, 2> alive;
    for (int i = 0; i < n; i++) {
        assert(alive[0].empty() || alive[1].empty());
        assert(len(alive[1]) <= 1);

        if (alive[0].empty() && alive[1].empty()) {
            alive[s[i] - '0'].push_back(i);
            continue;
        }

        if (s[i] == '0') {
            if (!alive[1].empty()) {
                edges.emplace_back(alive[1].back(), i);
                alive[1].back() = i;
            } else {
                alive[0].push_back(i);
            }
        } else {
            if (!alive[1].empty()) {
                edges.emplace_back(alive[1].back(), i);
                swap(alive[0], alive[1]);
            } else {
                edges.emplace_back(alive[0].back(), i);
                for (int i = len(alive[0]) - 2; i >= 0; i--) {
                    edges.emplace_back(alive[0][i], alive[0][i + 1]);
                }
                alive[1].push_back(alive[0][0]);
                alive[0].clear();
            }
        }
    }

    dbg(edges);
    assert(len(edges) == n - 1);
    for (auto &[v, u] : edges) {
        cout << (v + shift) % n + 1 << ' ' << (u + shift) % n + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}