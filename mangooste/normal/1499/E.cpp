#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T>
inline int normalize(T val, int mod) {
    if (val < -mod || val >= 2 * mod)
        val %= mod;
    if (val < 0)
        val += mod;
    if (val >= mod)
        val -= mod;
    return int(val);
}

template<int mod>
struct mval {
    int val;

    mval() : val(0) {}
    template<typename T> mval(T val) : val(normalize(val, mod)) {}

    explicit operator int() const { return val; }
    explicit operator long long() const { return val; }

    inline mval power(long long deg) const {
        deg = normalize(deg, mod - 1);
        mval prod = 1;
        mval a = *this;
        for (; deg; deg >>= 1, a *= a)
            if (deg & 1)
                prod *= a;
        return prod;
    }
    inline mval rev() const { return power(-1); }

    inline mval& operator+=(const mval m) { val += m.val; if (val >= mod) val -= mod; return *this; }
    inline mval& operator-=(const mval m) { val -= m.val; if (val < 0) val += mod; return *this; }
    inline mval& operator*=(const mval m) { val = 1ll * val * m.val % mod; return *this; }
    inline mval& operator/=(const mval m) { val = 1ll * val * m.rev().val % mod; return *this; }
    template<typename T> inline mval& operator=(const T x) { *this = mval(x); return *this; }

    inline friend mval operator+(const mval a, const mval b) { return mval(a) += b; }
    inline friend mval operator-(const mval a, const mval b) { return mval(a) -= b; }
    inline friend mval operator*(const mval a, const mval b) { return mval(a) *= b; }
    inline friend mval operator/(const mval a, const mval b) { return mval(a) /= b; }

    inline mval& operator++() { ++val; if (val == mod) val = 0; return *this; }
    inline mval operator++(int) { val++; if (val == mod) val = 0; return *this; }
    inline mval& operator--() { --val; if (val == -1) val = mod - 1; return *this; }
    inline mval operator--(int) { val--; if (val == -1) val = mod - 1; return *this; }

    inline bool operator==(const mval m) const { return val == m.val; }
    inline bool operator!=(const mval m) const { return val != m.val; }
    inline bool operator<(const mval m) const { return val < m.val; }
    inline bool operator>(const mval m) const { return val > m.val; }

    friend istream& operator>>(istream &in, mval &m) { long long x; in >> x; m = mval(x); return in; }
    friend ostream& operator<<(ostream &out, const mval m) { return out << m.val; }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = mval<MOD>;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = len(s), m = len(t);
    s.insert(s.begin(), 0);
    t.insert(t.begin(), 0);
    vec<vec<ar<mint, 2>>> dp(n + 1, vec<ar<mint, 2>>(m + 1, {0, 0}));
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = 1;
        if (i == 1 || s[i] != s[i - 1]) {
            dp[i][0][0] += dp[i - 1][0][0];
        }
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j][1] = 1;
        if (j == 1 || t[j] != t[j - 1]) {
            dp[0][j][1] += dp[0][j - 1][1];
        }
    }
    mint ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] != t[j]) {
                dp[i][j][0]  += dp[0][j][1];
                dp[i][j][1] += dp[i][0][0];
            }
            if (i != 1) {
                if (s[i] != t[j]) {
                    dp[i][j][0] += dp[i - 1][j][1];
                }
                if (s[i] != s[i - 1]) {
                    dp[i][j][0] += dp[i - 1][j][0];
                }
            }
            if (j != 1) {
                if (t[j] != s[i]) {
                    dp[i][j][1] += dp[i][j - 1][0];
                }
                if (t[j] != t[j - 1]) {
                    dp[i][j][1] += dp[i][j - 1][1];
                }
            }
            ans += dp[i][j][0] + dp[i][j][1];
        }
    }
    cout << ans << '\n';
}