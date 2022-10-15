#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct ModInt {
    static const int MOD = 998244353;
    int value;

    ModInt(long long x) : value(x % MOD) {}

    ModInt(int x = 0) : value(x < 0 ? x + MOD : x) {}

    ModInt(int x, int) : value(x) {} // unchecked constructor

    ModInt operator+() const { return *this; }

    ModInt operator+(ModInt m) const {
        int res = value + m.value;
        if (res >= MOD) res -= MOD;
        return {res, 0};
    }

    ModInt operator+=(ModInt m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    ModInt operator-() const { return {value ? MOD - value : 0, 0}; }

    ModInt operator-(ModInt m) const {
        return value - m.value;
    }

    ModInt operator-=(ModInt m) {
        value -= m.value;
        if (value < 0) value += MOD;
        return *this;
    }

    ModInt operator*(ModInt m) const { return value * 1LL * m.value; }

    ModInt operator*=(ModInt m) {
        value = (value * 1LL * m.value) % MOD;
        return *this;
    }

    ModInt power(int exp) const {
        if (exp == 0) return 1;
        if (exp & 1) return *this * power(exp - 1);
        return (*this * *this).power(exp / 2);
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
    vector<ModInt> fact(2 * n, 1);
    for (int i = 2; i < fact.size(); ++i) fact[i] = fact[i - 1] * i;
    auto binom = [&](int n, int k) { return fact[n] / fact[k] / fact[n - k]; };
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ll curL = 0, curR = a[n - 1];
    int j = n - 1;
    ModInt ans = 1;
    for (int i = 0; i + 1 <= j; ++i) {
        curL += a[i];
        while (curR < curL) {
            curR += a[--j];
        }
        if (curL == curR) {
            if (i >= j) break;
            ModInt cur = 0;
            int zl = 0, zr = 0;
            while (i + 1 < n && a[i + 1] == 0) i++, zl++;
            while (j && a[j - 1] == 0) j--, zr++;
            if (i + 1 == n) zl--, zr--;
            if (zl == zr && i + 1 >= j) {
                ans *= ModInt(2).power(zl + 1);
                break;
            }
            for (int x = 0; x <= min(zl, zr) + 1; ++x) {
                cur += binom(zl + 1, x) * binom(zr + 1, x);
            }
            ans *= cur;
        }
    }
    cout << ans << '\n';
}