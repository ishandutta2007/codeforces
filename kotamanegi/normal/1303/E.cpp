#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <iomanip>
#include <bitset>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-15;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if (i) os << " ";
        os << to_string(v[i]);
    }
    return os;
}

struct modint {
    ll n;
public:
    modint(const ll n = 0) : n((n% mod + mod) % mod) {}
    static modint pow(modint a, int m) {
        modint r = 1;
        while (m > 0) {
            if (m & 1) { r *= a; }
            a = (a * a); m /= 2;
        }
        return r;
    }
    modint& operator++() { *this += 1; return *this; }
    modint& operator--() { *this -= 1; return *this; }
    modint operator++(int) { modint ret = *this; *this += 1; return ret; }
    modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
    modint operator~() const { return (this->pow(n, mod - 2)); } // inverse
    friend bool operator==(const modint& lhs, const modint& rhs) {
        return lhs.n == rhs.n;
    }
    friend bool operator<(const modint& lhs, const modint& rhs) {
        return lhs.n < rhs.n;
    }
    friend bool operator>(const modint& lhs, const modint& rhs) {
        return lhs.n > rhs.n;
    }
    friend modint& operator+=(modint& lhs, const modint& rhs) {
        lhs.n += rhs.n;
        if (lhs.n >= mod) lhs.n -= mod;
        return lhs;
    }
    friend modint& operator-=(modint& lhs, const modint& rhs) {
        lhs.n -= rhs.n;
        if (lhs.n < 0) lhs.n += mod;
        return lhs;
    }
    friend modint& operator*=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * rhs.n) % mod;
        return lhs;
    }
    friend modint& operator/=(modint& lhs, const modint& rhs) {
        lhs.n = (lhs.n * (~rhs).n) % mod;
        return lhs;
    }
    friend modint operator+(const modint& lhs, const modint& rhs) {
        return modint(lhs.n + rhs.n);
    }
    friend modint operator-(const modint& lhs, const modint& rhs) {
        return modint(lhs.n - rhs.n);
    }
    friend modint operator*(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * rhs.n);
    }
    friend modint operator/(const modint& lhs, const modint& rhs) {
        return modint(lhs.n * (~rhs).n);
    }
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }

#define MAX_N 3030303
long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}
long long mod_inverse(long long a, long long m) {
    long long x, y;
    if (extgcd(a, m, x, y) == 1) return (m + x % m) % m;
    else return -1;
}
vector<long long> fact(MAX_N + 1, inf);
long long mod_fact(long long n, long long& e) {
    if (fact[0] == inf) {
        fact[0] = 1;
        if (MAX_N != 0) fact[1] = 1;
        for (ll i = 2; i <= MAX_N; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
    }
    e = 0;
    if (n == 0) return 1;
    long long res = mod_fact(n / mod, e);
    e += n / mod;
    if ((n / mod) % 2 != 0) return (res * (mod - fact[n % mod])) % mod;
    return (res * fact[n % mod]) % mod;
}
// return nCk
long long mod_comb(long long n, long long k) {
    if (n < 0 || k < 0 || n < k) return 0;
    long long e1, e2, e3;
    long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n - k, e3);
    if (e1 > e2 + e3) return 0;
    return (a1 * mod_inverse((a2 * a3) % mod, mod)) % mod;
}

using mi = modint;

mi mod_pow(mi a, ll n) {
    mi ret = 1;
    mi tmp = a;
    while (n > 0) {
        if (n % 2) ret *= tmp;
        tmp = tmp * tmp;
        n /= 2;
    }
    return ret;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(testcase, t) {
        string s, t;
        cin >> s >> t;
        int n = (int)s.size(), m = (int)t.size();
        int pos = 0;
        REP(i, n) {
            if (pos < m && s[i] == t[pos]) pos++;
        }
        if (pos == m) {
            cout << "YES" << "\n";
            continue;
        }
        bool ok = false;
        REP(i, m - 1) {
            string t1 = "", t2 = "";
            REP(j, m) {
                if (j <= i) t1 += t[j];
                else t2 += t[j];
            }
            int m1 = (int)t1.size(), m2 = (int)t2.size();
            vector<vector<int>> dp(n, vector<int>(m1 + 1, -inf));
            dp[0][0] = 0;
            if (s[0] == t1[0]) dp[0][1] = 0;
            if (s[0] == t2[0]) dp[0][0] = 1;
            FOR(j, 1, n) REP(k, m1 + 1) {
                dp[j][k] = dp[j - 1][k];
                if (k && dp[j - 1][k - 1] != -inf && s[j] == t1[k - 1]) dp[j][k] = max(dp[j][k], dp[j - 1][k - 1]);
                if (dp[j - 1][k] != -inf && dp[j - 1][k] != m2 && s[j] == t2[dp[j - 1][k]]) dp[j][k] = max(dp[j][k], dp[j - 1][k] + 1);
            }
            if (dp[n - 1][m1] == m2) ok = true;
        }
        if (ok) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}