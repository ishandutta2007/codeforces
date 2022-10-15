#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
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

#define answer(ans) {cout << (ans) << endl; return;}

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    auto check = [&](auto check, int x) -> bool {
        if (x % 4 == 2 || x == 0) return true;
        if (x % 2 == 1) return  !binary_search(a.begin(), a.end(), x / 2) && check(check, x / 2);
        if (x % 4 == 0) return  !binary_search(a.begin(), a.end(), x / 4) && check(check, x / 4);
    };
    vector<ll> roots;
    for (int i = 0; i < n; ++i) {
        if (check(check, a[i])) roots.push_back(a[i]);
    }
    ModInt ans = 0;
    vector<ModInt> f(p + 4);
    f[1] = 1;
    for (int i = 2; i < f.size(); ++i) f[i] = f[i - 1] + f[i - 2];
    for (ll x: roots) {
        for (int len = 0; len <= 30; ++len) {
            if (x < (1LL << len) && len <= p) {
                ans += f[p - len + 3] - 1;
                break;
            }
        }
    }
    cout << ans << '\n';
}