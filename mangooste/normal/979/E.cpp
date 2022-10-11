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
int normalize(T val, int mod) {
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

    mval power(long long deg) const {
        deg = normalize(deg, mod - 1);
        mval prod = 1;
        mval a = *this;
        for (; deg; deg >>= 1, a *= a)
            if (deg & 1)
                prod *= a;
        return prod;
    }
    mval rev() const { return power(-1); }

    mval& operator+=(const mval m) { val += m.val; if (val >= mod) val -= mod; return *this; }
    mval& operator-=(const mval m) { val -= m.val; if (val < 0) val += mod; return *this; }
    mval& operator*=(const mval m) { val = 1ll * val * m.val % mod; return *this; }
    mval& operator/=(const mval m) { val = 1ll * val * m.rev().val % mod; return *this; }
    template<typename T> mval& operator=(const T x) { *this = mval(x); return *this; }

    friend mval operator+(const mval a, const mval b) { return mval(a) += b; }
    friend mval operator-(const mval a, const mval b) { return mval(a) -= b; }
    friend mval operator*(const mval a, const mval b) { return mval(a) *= b; }
    friend mval operator/(const mval a, const mval b) { return mval(a) /= b; }

    mval& operator++() { ++val; if (val == mod) val = 0; return *this; }
    mval operator++(int) { val++; if (val == mod) val = 0; return *this; }
    mval& operator--() { --val; if (val == -1) val = mod - 1; return *this; }
    mval operator--(int) { val--; if (val == -1) val = mod - 1; return *this; }

    bool operator==(const mval m) const { return val == m.val; }
    bool operator!=(const mval m) const { return val != m.val; }
    bool operator<(const mval m) const { return val < m.val; }
    bool operator>(const mval m) const { return val > m.val; }

    friend istream& operator>>(istream &in, mval &m) { long long x; in >> x; m = mval(x); return in; }
    friend ostream& operator<<(ostream &out, const mval m) { return out << m.val; }
};

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = mval<MOD>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, p;
    cin >> n >> p;
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;

    vector<mint> p2(2 * n * n + 4, 1);
    for (int i = 1; i < len(p2); i++)
        p2[i] = p2[i - 1] + p2[i - 1];

    vector<vector<vector<mint>>> dp(1, vector<vector<mint>>(1, vector<mint>(1)));
    dp[0][0][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        int suf = n - i + 1;
        vector<vector<vector<mint>>> ndp(suf, vector<vector<mint>>(suf, vector<mint>(suf)));

        for (auto color : {0, 1})
            if (c[i] == -1 || color == c[i])
                for (int w = 0; w < suf - 1; w++)
                    for (int w0 = 0; w0 < suf - 1; w0++)
                        for (int w1 = 0; w0 + w1 < suf - 1; w1++) {
                            int cnt = color == 0 ? w1 : w0;
                            int another = (color == 0 ? n - i - 1 - w : w) - cnt;
                            if (another < 0)
                                continue;

                            ndp[w + (color == 0)][w0][w1] += dp[w][w0][w1] * (cnt == 0 ? 0 : p2[cnt - 1]) * p2[another];
                            ndp[w + (color == 0)][w0 + (color == 0)][w1 + (color == 1)] += dp[w][w0][w1] * (cnt == 0 ? 1 : p2[cnt - 1]) * p2[another];
                        }

        swap(dp, ndp);
    }

    mint answer = 0;
    for (int w = 0; w <= n; w++)
        for (int w0 = 0; w0 <= n; w0++)
            for (int w1 = 0; w0 +  w1 <= n; w1++)
                if (((w0 & 1) ^ (w1 & 1)) == p)
                    answer += dp[w][w0][w1] * p2[w * (w - 1) / 2 + (n - w) * (n - w - 1) / 2];

    cout << answer << '\n';
}