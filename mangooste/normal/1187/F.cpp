#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

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

mint len(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2) - max(l1, l2) + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> l(n);
    for (auto &x : l)
        cin >> x;

    vector<int> r(n);
    for (auto &x : r)
        cin >> x;

    vector<mint> e(n);
    e[0] = 1;
    for (int i = 1; i < n; i++)
        e[i] = 1 - len(l[i], r[i], l[i - 1], r[i - 1]) / (r[i] - l[i] + 1) / (r[i - 1] - l[i - 1] + 1);

    mint sum = accumulate(all(e), mint(0));
    mint answer = 0;
    for (int i = 0; i < n; i++) {
        mint current = sum - e[i] - (i ? e[i - 1] : 0) - (i + 1 < n ? e[i + 1] : 0);
        answer += current * e[i];
        answer += e[i];
    }

    for (int i = 0; i + 2 < n; i++) {
        mint e = 0;
        e += len(l[i], r[i], l[i + 1], r[i + 1]) * (r[i + 2] - l[i + 2] + 1);
        e += len(l[i + 1], r[i + 1], l[i + 2], r[i + 2]) * (r[i] - l[i] + 1);
        e -= max(0, min({r[i], r[i + 1], r[i + 2]}) - max({l[i], l[i + 1], l[i + 2]}) + 1);
        answer += (1 - e / (r[i] - l[i] + 1) / (r[i + 1] - l[i + 1] + 1) / (r[i + 2] - l[i + 2] + 1)) * 2;
    }

    if (n > 1)
        answer += 2 * e[1];

    cout << answer << '\n';
}