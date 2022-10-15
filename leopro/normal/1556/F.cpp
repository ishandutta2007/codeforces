#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
 
using ll = long long;
using ull = unsigned long long;
using namespace std;
 
void solve();
 
signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
 
struct ModInt {
    static const int MOD = 1e9 + 7;
    int value;
 
    ModInt(int i = 0) : value(i) {}
 
    ModInt operator+(ModInt m) const {
        ModInt lhs = *this;
        lhs += m;
        return lhs;
    }
 
    ModInt operator+=(ModInt m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return value;
    }
 
    ModInt operator-(ModInt m) const {
        ModInt lhs = *this;
        lhs -= m;
        return lhs;
    }
 
    ModInt operator-=(ModInt m) {
        value -= (m.value - MOD);
        if (value >= MOD) value -= MOD;
        return value;
    }
 
    ModInt operator*(ModInt m) const { return (value * 1LL * m.value) % MOD; }
 
    ModInt operator*=(ModInt m) {
        value = (value * 1LL * m.value) % MOD;
        return value;
    }
 
    ModInt power(int exp) {
        if (exp == 0) return 1;
        ModInt res = (exp & 1 ? value : 1);
        ModInt half = power(exp >> 1);
        return res * half * half;
    }
 
    ModInt operator/(ModInt m) const { return *this * m.power(MOD - 2); }
 
    ModInt operator/=(ModInt m) { return *this *= m.power(MOD - 2); }
 
    friend std::istream &operator>>(std::istream &is, ModInt &m) {
        is >> m.value;
        return is;
    }
 
    friend std::ostream &operator<<(std::ostream &os, const ModInt &m) {
        os << m.value;
        return os;
    }
 
    explicit operator int() const { return value; }
};
 
vector<ModInt> winAll;
int n;
 
ModInt transfer(int cur, int next) {
    ModInt ans = 1;
    for (int i = 0; i < n; ++i) {
        if ((1 << i) & ~next) continue;
        ModInt fail = 1;
        fail *= winAll[i * (1 << n) + cur];
        ans *= ModInt(1) - fail;
    }
    return ans;
}
 
vector<ModInt> probability;
 
ModInt findAns(int cur) {
    ModInt &p = probability[cur];
    if (cur == (1 << n) - 1) return p = 1;
    for (int next = (cur + 1) | cur; next < (1 << n); next = (next + 1) | cur) {
        auto d = probability[next];
        auto t = transfer(cur, next ^ cur);
        if (__builtin_popcount(next ^ cur) % 2 == 1) {
            p += d * t;
        } else {
            p -= d * t;
        }
    }
    return p;
}
 
void solve() {
    cin >> n;
    vector<int> f(n);
    for (int &x : f) cin >> x;
    vector<vector<ModInt>> w(n, vector<ModInt>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            w[i][j] = ModInt(f[i]) / (f[i] + f[j]);
        }
    }
    winAll.assign(n * (1 << n), 1);
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int bit = 0; bit < n; ++bit) {
                if (~mask & (1 << bit)) continue;
                winAll[i * (1 << n) + mask] *= w[i][bit];
            }
        }
    }
    probability.assign(1 << n, 0);
    for (int mask = (1 << n) - 1; mask > 0; --mask) findAns(mask);
    ModInt e = 0;
    for (int i = 0; i < n; ++i) e += probability[1 << i];
    cout << e << '\n';
}