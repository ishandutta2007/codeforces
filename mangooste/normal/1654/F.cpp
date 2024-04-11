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

    int n;
    string s;
    cin >> n >> s;
    
    int best_mask = y_combinator([&](auto solve, const vector<int> &a) -> int {
        if (len(a) == 1) return 0;

        vector<ll> values, first(len(a) >> 1), second(len(a) >> 1);
        values.reserve(len(a));
        for (int i = 0; i < len(a); i += 2) {
            first[i >> 1] = ll(1e9) * a[i] + a[i + 1];
            values.push_back(first[i >> 1]);
            second[i >> 1] = ll(1e9) * a[i + 1] + a[i];
            values.push_back(second[i >> 1]);
        }
        sort(all(values));
        values.resize(unique(all(values)) - values.begin());

        auto query = [&](ll x) {
            return lower_bound(all(values), x) - values.begin();
        };
        for (auto &x : first) {
            x = query(x) + 1;
        }
        for (auto &x : second) {
            x = query(x) + 1;
        }
        
        int mask1 = solve(vector<int>(all(first))) << 1;
        int mask2 = solve(vector<int>(all(second))) << 1 | 1;

        vector<int> a1(len(a)), a2(len(a));
        for (int i = 0; i < len(a); i++) {
            a1[i ^ mask1] = a[i];
            a2[i ^ mask2] = a[i];
        }
        return a1 < a2 ? mask1 : mask2;
    })(vector<int>(all(s)));

    string ans(len(s), '?');
    for (int i = 0; i < len(s); i++) {
        ans[i ^ best_mask] = s[i];
    }
    cout << ans << '\n';
}