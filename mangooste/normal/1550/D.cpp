#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = mval<MOD>;

namespace factorials {
    vector<mint> fact;
    vector<mint> rfact;
    vector<mint> inv;

    void init(int n) {
        fact = vector<mint>(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        rfact = vector<mint>(n + 1);
        rfact.back() = fact.back().rev();
        for (int i = n; i > 0; i--)
            rfact[i - 1] = rfact[i] * i;

        inv = vector<mint>(n + 1);
        for (int i = 1; i <= n; i++)
            inv[i] = rfact[i] * fact[i - 1];
    }

    inline mint C(int n, int k) {
        if (n < k || k < 0 || n < 0)
            return 0;

        return fact[n] * rfact[k] * rfact[n - k];
    }
} // namespace factorials

using factorials::fact;
using factorials::rfact;
using factorials::inv;
using factorials::C;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--, l *= -1;

    // mint answer = 0;
    // for (int val = 1; val <= max(l, r); val++) {
    //     int suf = max(0, val - l);
    //     int pref = min(n - 1, r - val);
    //     int only_neg = suf;
    //     int only_pos = n - 1 - pref;
    //     int both = n - only_pos - only_neg;
    //     assert(both == pref - suf + 1);
    //     answer += C(both, n / 2 - only_neg);
    //     if (n & 1)
    //         answer += C(both, n / 2 - only_pos);
    // }
    // cout << answer << '\n';

    int start_suf = 1 - l;
    int start_pref = r - 1;

    int cnt = max(0, min(-start_suf, start_pref - (n - 1)));
    mint answer = C(n, n / 2) * cnt;
    if (n & 1)
        answer *= 2;

    for (int pref = min(n - 1, start_pref); pref >= 0; pref--) {
        int suf = start_suf + (start_pref - pref);
        if (suf < 0) {
            answer += C(pref + 1, n / 2);
            if (n & 1)
                answer += C(pref + 1, n / 2 - (n - 1 - pref));
        }
    }

    for (int suf = max(start_suf, 0); suf <= n; suf++) {
        int pref = min(n - 1, start_pref - (suf - start_suf));
        answer += C(pref - suf + 1, n / 2 - suf);
        if (n & 1)
            answer += C(pref - suf + 1, n / 2 - (n - 1 - pref));
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    factorials::init(1e6);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}