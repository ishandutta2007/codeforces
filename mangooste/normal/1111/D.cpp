#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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
    vector<mint> fact, rfact, inv;

    inline void init(int n) {
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
        if (n < k || k < 0)
            return 0;
        return fact[n] * rfact[k] * rfact[n - k];
    }
} // namespace factorials

using factorials::fact;
using factorials::rfact;
using factorials::inv;
using factorials::C;

struct DP {
    vec<mint> dp;

    DP() {}
    DP(int n) : dp(n + 1) { dp[0] = 1; }

    inline void add(int x) {
        if (x >= len(dp)) return;
        for (int i = len(dp) - 1; i >= x; i--) {
            dp[i] += dp[i - x];
        }
    }

    inline mint operator+(const DP &d) const {
        assert(len(dp) == len(d.dp));
        mint ans = 0;
        for (int i = 0; i < len(dp); i++) {
            ans += dp[i] * d.dp[len(dp) - 1 - i];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    int n = len(s);
    vec<int> id(256, -1);
    vec<int> cnt(256);
    int sz = 0;
    for (auto x : s) {
        cnt[x]++;
        if (id[x] == -1) id[x] = sz++;
    }
    vec<pair<int, int>> sets;
    for (int i = 0; i < 256; i++) {
        if (id[i] == -1) continue;
        sets.emplace_back(cnt[i], id[i]);
    }
    vec<DP> dp(sz, DP(n / 2));
    for (int i = 0; i < sz - 1; i++) {
        dp[i + 1] = dp[i];
        dp[i + 1].add(sets[i].first);
    }
    vec<vec<mint>> ans(sz, vec<mint>(sz));
    vec<DP> cur(sz, DP(n / 2));
    for (int i = sz - 1; i >= 0; i--) {
        for (int j = i; j < sz; j++) {
            ans[sets[i].second][sets[j].second] = ans[sets[j].second][sets[i].second] = cur[sets[j].second] + dp[i];
        }
        for (int j = 0; j < sz; j++) {
            if (j == sets[i].second) continue;
            cur[j].add(sets[i].first);
        }
    }
    factorials::init(n);
    mint coeff = 2 * fact[n / 2].power(2);
    for (auto [len, id] : sets) {
        coeff *= rfact[len];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y, x--, y--;
        cout << ans[id[s[x]]][id[s[y]]] * coeff << '\n';
    }
}