#pragma GCC optimize("O3")

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

// constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
constexpr int MOD = 31607;
using mint = mval<MOD>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<mint>> a(n, vector<mint>(n));
    vector<vector<mint>> rev_a(n, vector<mint>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a[i][j] = mint(x) / 10000;
            rev_a[i][j] = mint(1) / a[i][j];
        }

    const int MASK = 1 << n;
    vector<vector<mint>> rows_prod(MASK, vector<mint>(n, 1));
    for (int mask = 0; mask < MASK; mask++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (((mask >> j) & 1) == 0)
                    rows_prod[mask][i] *= a[i][j];

    auto solve = [&]() {
        vector<mint> cols_prod(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cols_prod[j] *= a[i][j];

        vector<mint> mask_prod(MASK, 1);
        for (int mask = 1; mask < MASK; mask++) {
            int bit = __lg(mask);
            mask_prod[mask] = mask_prod[mask ^ (1 << bit)] * cols_prod[bit];
        }

        mint answer = 0;
        for (int mask = 0; mask < MASK; mask++) {
            array<mint, 2> dp{1, 0};
            array<mint, 2> new_dp;
            for (int i = 0; i < n; i++) {
                new_dp.fill(0);
                for (int j : {0, 1})
                    new_dp[j] = dp[j] + dp[j ^ 1] * rows_prod[mask][i];

                swap(dp, new_dp);
            }

            for (int j : {0, 1})
                if ((j + __builtin_popcount(mask)) & 1)
                    answer -= dp[j] * mask_prod[mask];
                else
                    answer += dp[j] * mask_prod[mask];
        }
        return answer;
    };

    mint answer = 0;
    answer += solve();

    auto initial_a = a;
    {
        for (int mask = 0; mask < MASK; mask++)
            for (int i = 0; i < n; i++)
                if (((mask >> i) & 1) == 0)
                    rows_prod[mask][i] *= rev_a[i][i];

        mint prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= a[i][i];
            a[i][i] = 1;
        }
        answer -= solve() * prod;
        a = initial_a;

        for (int mask = 0; mask < MASK; mask++)
            for (int i = 0; i < n; i++)
                if (((mask >> i) & 1) == 0)
                    rows_prod[mask][i] *= a[i][i];
    }
    {
        for (int mask = 0; mask < MASK; mask++)
            for (int i = 0; i < n; i++)
                if (((mask >> (n - 1 - i)) & 1) == 0)
                    rows_prod[mask][i] *= rev_a[i][n - 1 - i];

        mint prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= a[i][n - 1 - i];
            a[i][n - 1 - i] = 1;
        }
        answer -= solve() * prod;
        a = initial_a;

        for (int mask = 0; mask < MASK; mask++)
            for (int i = 0; i < n; i++)
                if (((mask >> (n - 1 - i)) & 1) == 0)
                    rows_prod[mask][i] *= a[i][n - 1 - i];
    }
    {
        for (int mask = 0; mask < MASK; mask++)
            for (int i = 0; i < n; i++)
                if (((mask >> (n - 1 - i)) & 1) == 0)
                    rows_prod[mask][i] *= rev_a[i][n - 1 - i];

        for (int mask = 0; mask < MASK; mask++)
            for (int i = 0; i < n; i++)
                if (i != n - 1 - i && ((mask >> i) & 1) == 0)
                    rows_prod[mask][i] *= rev_a[i][i];

        mint prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= a[i][i];
            a[i][i] = 1;
            if (i != n - 1 - i)
                prod *= a[i][n - 1 - i];

            a[i][n - 1 - i] = 1;
        }
        answer += solve() * prod;
    }
    cout << 1 - answer << '\n';
}