#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

int MOD;

struct ModInt {
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

void solve() {
    int n;
    cin >> n >> MOD;
    vector<ModInt> suf(n + 2);
    auto add = [&](int i, ModInt x) { suf[i] += x; };
    auto get = [&](int l, int r) {
        if (r > n + 1) r = n + 1;
        return suf[l] - suf[r];
    };
    auto relax = [&](int i) { suf[i] = suf[i + 1]; };
    add(n, 1);
    for (int i = n - 1; i > 0; --i) {
        relax(i);
        add(i, get(i + 1, n + 1));
        for (int m = 2; i * m <= n; ++m) {
            add(i, get(i * m, (i + 1) * m));
        }
    }
    cout << get(1, 2) << '\n';
}