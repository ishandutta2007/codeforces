#include <bits/stdc++.h>

#include <utility>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
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

    ModInt(long long ll) : value(ll % MOD) {}

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int &x: a) cin >> x;
    vector<ModInt> f(a[0] + 2 + n, 1);
    for (int i = 2; i <= a[0] + n + 1; ++i) f[i] = f[i - 1] * i;
    auto c = [&](int n, int k)->ModInt { return (k > n)? 0: f[n] / f[k] / f[n - k]; };
    ModInt ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += c(a[i] + i, i + 1);
    }
    cout << ans << '\n';
}