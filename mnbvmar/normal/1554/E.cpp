#include <bits/stdc++.h>
#define int int64_t

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

struct alignas(8) mod_int {
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

vector<bool> right_, minus_;
vector<vector<int>> tree;
int cur_div;

void dfs(int cur, int prev) {
    int cnt = 0;
    for (auto next : tree[cur]) {
        if (next != prev) {
            dfs(next, cur);
            if (!right_[next] && !minus_[next]) return;
            if (right_[next]) cnt++;
        }
    }
    if (cnt % cur_div == 0) right_[cur] = true;
    if (cnt % cur_div == cur_div - 1) minus_[cur] = true;
};

void solve() {
    int n;
    cin >> n;
    tree.clear(); right_.clear(); minus_.clear();
    tree.resize(n);
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
    right_.resize(n);
    minus_.resize(n);
    for (auto d : divisors) {
        cur_div = d;
        fill(right_.begin(), right_.end(), false);
        fill(minus_.begin(), minus_.end(), false);
        dfs(0, 0);
        if (right_[0]) ans[d] = 1;
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