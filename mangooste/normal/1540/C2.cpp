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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;

    vector<int> b(n - 1);
    for (auto &x : b)
        cin >> x;

    vector<int> pref_sum(n);
    for (int i = 0, sum_b = 0; i < n - 1; i++) {
        sum_b += b[i];
        pref_sum[i + 1] = pref_sum[i] + sum_b;
    }

    auto solve_one = [&](int x) {
        vector<mint> dp{1};
        for (int i = 0; i < n; i++) {
            int mn_pref = (i + 1) * x + pref_sum[i];
            vector<mint> ndp(len(dp) + c[i]);
            mint current_sum = 0;
            for (int j = 0; j < len(ndp); j++) {
                if (j < len(dp))
                    current_sum += dp[j];

                if (j - c[i] - 1 >= 0)
                    current_sum -= dp[j - c[i] - 1];

                if (j >= mn_pref)
                    ndp[j] = current_sum;
            }
            swap(dp, ndp);
        }
        return accumulate(all(dp), mint(0));
    };

    mint prod = 1;
    for (int i = 0; i < n; i++)
        prod *= c[i] + 1;

    const int A = 1e5;
    vector<int> maybe;
    vector<mint> answer;
    for (int x = -A; x <= A; x++) {
        bool ok = true;
        bool all_good = true;
        for (int i = 0, sum_c = 0; i < n; i++) {
            int mn_pref = (i + 1) * x + pref_sum[i];
            sum_c += c[i];
            all_good &= mn_pref <= 0;
            if (mn_pref > sum_c) {
                ok = false;
                break;
            }
        }
        if (all_good) {
            maybe.push_back(x);
            answer.push_back(prod);
        } else if (ok) {
            maybe.push_back(x);
            answer.push_back(solve_one(x));
        }
    }
    answer.push_back(0);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << answer[lower_bound(all(maybe), x) - maybe.begin()] << '\n';
    }
}