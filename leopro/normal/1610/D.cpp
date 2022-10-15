#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct ModInt {
    static const int MOD = 1e9+7;
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
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int odd = 0, even = 0;
    for (int x : a) (x % 2 == 0 ? even : odd)++;
    ModInt ans = ModInt(2).power(even) * (ModInt(2).power(odd) - 1);
    for (int p = 2; p < 1e9; p *= 2) {
        int cnt1 = 0, cnt2 = 0;
        for (int x : a) {
            if (x % p != 0) continue;
            (x % (2 * p) == 0 ? cnt2 : cnt1)++;
        }
        if (cnt1 == 0) continue;
        ans += (ModInt(2).power(cnt1 - 1) - 1) * ModInt(2).power(cnt2);
    }
    cout << ans << '\n';
}