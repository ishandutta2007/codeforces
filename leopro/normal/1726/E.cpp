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
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct ModInt {
    static const int MOD = 998244353;
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

    static ModInt g() {
        int phi = MOD - 1;
        vector<int> divisors;
        for (int i = 2; i * i <= phi; ++i) {
            if (phi % i == 0) divisors.push_back(i);
            do {
                phi /= i;
            } while (phi % i == 0);
        }
        if (phi > 1) divisors.push_back(phi);
        phi = MOD - 1;
        for (int g = 2;; ++g) {
            if (all_of(divisors.begin(), divisors.end(), [&](int d) { return (int) ModInt(g).power(phi / d) != 1; })) {
                return g;
            }
        }
    }

    static int modulo() { return MOD; }
};

vector<int> rev;
vector<ModInt> p;

void init(int n) {
    rev.resize(n);
    p.resize(n, 1);
    for (int i = 1; i < n; ++i) {
        rev[i] = rev[i / 2] / 2 + ((i & 1) << (__lg(n) - 1));
    }
    ModInt omega = ModInt::g().power((ModInt::modulo() - 1) / n);
    for (int i = 1; i < n; ++i) p[i] = p[i - 1] * omega;
}

void fft(vector<ModInt> &v, int lg) {
    int n = 1 << lg;
    for (int i = 0; i < n; ++i) {
        if (i < rev[i]) swap(v[i], v[rev[i]]);
    }
    for (int lvl = 0; lvl < lg; ++lvl) {
        for (int i = 0; i < n; ++i) {
            if ((i & ((1 << (lvl + 1)) - 1)) == 0) i += 1 << lvl;
            int j = i - (1 << lvl);
            auto e = v[j], o = v[i] * p[(i & ((1 << lvl) - 1)) * (1 << (lg - lvl - 1))];
            v[j] = e + o;
            v[i] = e - o;
        }
    }
}

vector<ModInt> operator*(vector<ModInt> a, vector<ModInt> b) {
    int sz = a.size() + b.size() - 1;
    int lg = __lg(max(sz - 1, 1)) + 1;
    int n = 1 << lg;
    init(n);
    a.resize(n);
    b.resize(n);
    fft(a, lg);
    fft(b, lg);
    vector<ModInt> c(n);
    for (int i = 0; i < n; ++i) c[i] = a[i] * b[i];
    fft(c, lg);
    reverse(c.begin() + 1, c.end());
    auto inv_n = ModInt(1) / n;
    for (auto &x: c) x *= inv_n;
    return c;
}

void solve() {
    int n = 3e5;
    vector<ModInt> f(n + 1, 1);
    for (int i = 1; i < f.size(); ++i) f[i] = f[i - 1] * i;
    vector<ModInt> a(n + 1), b(n + 1);
    ModInt t = 2;
    for (int p = 0; 2 * p <= n; ++p) a[2 * p] = ModInt(1) / f[p] / t.power(p);
    for (int p = 0; p <= n; ++p) b[p] = ModInt(1) / f[p];
    auto c = a * b;
    int q = 1;cin >> q;for (int tc = 0; tc < q; ++tc) {
        cin >> n;
        ModInt ans = 0;
        for (int q = 0; 4 * q <= n; ++q) {
            ans += f[n - 2 * q] / f[q] * c[n - 4 * q];
        }
        cout << ans << '\n';
    }
}