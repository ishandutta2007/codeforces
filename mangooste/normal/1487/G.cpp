#pragma GCC optimize("O3,Ofast,unroll-loops")

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

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = mval<MOD>;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cnt(26);
    for (auto &x : cnt)
        cin >> x;

    vector<vector<mint>> dp(26, vector<mint>(26));
    for (int a = 0; a < 26; a++)
        for (int b = 0; b < 26; b++)
            dp[a][b] = 1;

    for (int i = 2; i < n; i++) {
        vector<vector<mint>> ndp(26, vector<mint>(26));
        for (int a = 0; a < 26; a++)
            for (int b = 0; b < 26; b++)
                for (int c = 0; c < 26; c++)
                    if (a != c)
                        ndp[b][a] += dp[c][b];

        dp = ndp;
    }

    mint answer = 0;
    for (int a = 0; a < 26; a++)
        for (int b = 0; b < 26; b++)
            answer += dp[a][b];

    vector<vector<array<array<mint, 3>, 3>>> dp2(n, vector<array<array<mint, 3>, 3>>(n));
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            dp2[(a == 0) + (b == 0)][(a == 1) + (b == 1)][a][b] = mint(24).power((a == 2) + (b == 2));

    for (int i = 2; i < n; i++) {
        vector<vector<array<array<mint, 3>, 3>>> ndp2(n, vector<array<array<mint, 3>, 3>>(n));
        for (int cnt1 = 0; cnt1 < n; cnt1++)
            for (int cnt2 = 0; cnt1 + cnt2 <= i + 1 && cnt2 < n; cnt2++)
                for (int a = 0; a < 3; a++)
                    for (int b = 0; b < 3; b++)
                        for (int c = 0; c < 3; c++) {
                            if (a != 2 && a == c)
                                continue;

                            int ncnt1 = cnt1 - (a == 0);
                            int ncnt2 = cnt2 - (a == 1);
                            if (ncnt1 < 0 || ncnt2 < 0)
                                continue;

                            mint coeff = 1;
                            if (a == 2)
                                coeff = (c == a ? 23 : 24);

                            ndp2[cnt1][cnt2][b][a] += dp2[ncnt1][ncnt2][c][b] * coeff;
                        }

        dp2 = ndp2;
    }

    for (int a = 0; a < 26; a++)
        for (int cnt1 = cnt[a] + 1; cnt1 < n; cnt1++)
            for (int cnt2 = 0; cnt2 < n; cnt2++)
                for (int a = 0; a < 3; a++)
                    for (int b = 0; b < 3; b++)
                        answer -= dp2[cnt1][cnt2][a][b];

    for (int a = 0; a < 26; a++)
        for (int b = a + 1; b < 26; b++)
            for (int cnt1 = cnt[a] + 1; cnt1 < n; cnt1++)
                for (int cnt2 = cnt[b] + 1; cnt2 < n; cnt2++)
                    for (int a = 0; a < 3; a++)
                        for (int b = 0; b < 3; b++)
                            answer += dp2[cnt1][cnt2][a][b];

    cout << answer << '\n';
}