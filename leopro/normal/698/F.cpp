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

int gcd(int x, int y) {
    return x == 0 ? y : gcd(y % x, x);
}

bool coprime(int x, int y) { return gcd(x, y) == 1; }

int solve(int n, vector<int> p) {
    vector<int> minPrime(n + 1, 1);
    vector<int> primes;
    primes.reserve(n);
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 1) {
            minPrime[i] = i;
            primes.push_back(i);
        }
        for (int x: primes) {
            if (x > minPrime[i] || i * x > n) break;
            minPrime[i * x] = x;
        }
    }
    vector<int> f(n + 1), g(n + 1);
    for (int x: primes) {
        f[x] = n / x;
        g[x] = n / x;
    }
    vector<bool> inP(n + 1);
    f[1] = g[1] = 1;
    int cur = n;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0) continue;
        inP[p[i]] = true;
        int x = i + 1, y = p[i];
        vector<int> df, dg;
        if (x == 1) df.push_back(1);
        while (x > 1) {
            df.push_back(minPrime[x]);
            while (minPrime[x] == minPrime[x / minPrime[x]]) x /= minPrime[x];
            x /= minPrime[x];
        }
        if (y == 1) dg.push_back(1);
        while (y > 1) {
            dg.push_back(minPrime[y]);
            while (minPrime[y] == minPrime[y / minPrime[y]]) y /= minPrime[y];
            y /= minPrime[y];
        }
        if (df.size() != dg.size()) { return 0; }
        sort(df.begin(), df.end(), [&](int d1, int d2) { return f[d1] < f[d2]; });
        sort(dg.begin(), dg.end(), [&](int d1, int d2) { return g[d1] < g[d2]; });
        for (int j = 0; j < df.size(); ++j) {
            if (f[df[j]] != g[dg[j]]) { return 0; }
            if (j == 0 || f[df[j]] != f[df[j - 1]]) cur++;
            f[df[j]] = g[dg[j]] = cur;
        }
    }
    ModInt ans = 1;
    vector<ModInt> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = fact[i - 1] * i;
    vector<int> cnt(cur + 1);
    for (int x: f) if (x) cnt[x]++;
    for (int c: cnt) ans *= fact[c];
    vector<int> sf(n + 1);
    for (int x = 1; x <= n; ++x) {
        if (inP[x]) continue;
        int y = x;
        vector<int> d;
        while (y > 1) {
            d.push_back(minPrime[y]);
            while (minPrime[y] == minPrime[y / minPrime[y]]) y /= minPrime[y];
            y /= minPrime[y];
        }
        for (int z : d) y *= z;
        sf[y]++;
    }
    for (int x = 1; x <= n; ++x) {
        ans *= fact[sf[x]];
    }
    return (int) ans;
}


void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &x: p) cin >> x;
    cout << solve(n, p) << endl;
}