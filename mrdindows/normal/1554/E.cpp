// Not my code https://codeforces.com/blog/entry/94758
 
#include <bits/stdc++.h>
 
using namespace std;
 
void solve();
 
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}
 
struct mod_int {
    static const int MOD = 998244353;
    int value;
 
    mod_int(int i = 0) : value(i) {}
 
    mod_int operator+(mod_int m) const {
        mod_int lhs = *this;
        lhs += m;
        return lhs;
    }
 
    mod_int operator+=(mod_int m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return value;
    }
 
    mod_int operator-(mod_int m) const {
        mod_int lhs = *this;
        lhs -= m;
        return lhs;
    }
 
    mod_int operator-=(mod_int m) {
        value -= (m.value - MOD);
        if (value >= MOD) value -= MOD;
        return value;
    }
 
    mod_int operator*(mod_int m) const { return (value * 1LL * m.value) % MOD; }
 
    mod_int operator*=(mod_int m) {
        value = (value * 1LL * m.value) % MOD;
        return value;
    }
 
    mod_int power(int exp) {
        if (exp == 0) return 1;
        mod_int res = (exp & 1 ? value : 1);
        mod_int half = power(exp >> 1);
        return res * half * half;
    }
 
    mod_int operator/(mod_int m) const { return *this * m.power(MOD - 2); }
 
    mod_int operator/=(mod_int m) { return *this *= m.power(MOD - 2); }
 
    friend std::istream &operator>>(std::istream &is, mod_int &m) {
        is >> m.value;
        return is;
    }
 
    friend std::ostream &operator<<(std::ostream &os, const mod_int &m) {
        os << m.value;
        return os;
    }
 
    explicit operator int() const { return value; }
};
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> divisors;
    for (int i = 2; i <= n; ++i) {
        if ((n - 1) % i == 0) divisors.push_back(i);
    }
    vector<mod_int> ans(n + 1);
    ans[1] = mod_int(2).power(n - 1);
    for (auto d : divisors) {
        auto dfs = [&](auto dfs, int cur, int prev) -> pair<bool, bool> {
            int cnt = 0;
            bool bad = false;
            for (auto next : tree[cur]) {
                if (next != prev) {
                    auto [right_next, minus_next] = dfs(dfs, next, cur);
                    if (right_next) cnt++;
                    else if (!minus_next) bad = true;
                }
            }
            if (bad) return {false, false};
            return {cnt % d == 0, cnt % d == d - 1};
        };
        if (dfs(dfs, 0, 0).first) {
            ans[d] = 1;
        }
    }
    vector<vector<int>> dividers(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            dividers[j].push_back(i);
        }
    }
    for (int i = n; i > 0; --i) {
        for (auto d : dividers[i]) ans[d] -= ans[i];
    }
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
}