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
    #define dprint(...)
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

void solve(int test_num) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> st, par(2 * n, -1);
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {
            assert(!st.empty());
            par[st.back()] = i;
            st.pop_back();
        }
    }
    assert(st.empty());

    int ans = 2 * n;
    y_combinator([&](auto solve, int l, int r) -> void {
        if (r < l) return;

        vector<int> pos;
        ans--;
        for (int i = par[l];;) {
            pos.push_back(i);
            if (i == r) break;
            i = par[i + 1];
            ans--;
        }
        assert(!pos.empty());

        solve(l + 1, pos[0] - 1);
        for (int i = 1; i < len(pos); i++) {
            solve(pos[i - 1] + 1, pos[i]);
        }
    })(0, 2 * n - 1);

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}