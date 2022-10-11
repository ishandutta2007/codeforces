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

inline vector<int> zFunction(const string s) {
    int n = int(s.size());
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    return z;
}

inline int count(const string &s, const string &t, int need = -1) {
    auto z = zFunction(t + "#" + s);

    int res = 0;
    for (int i = len(t) + 1; i < len(z); i++)
        if (need == -1 || (i - len(t) - 1 <= need && i - len(t) - 1 + z[i] > need))
            res += z[i] == len(t);

    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s0, t;
    cin >> s0 >> t;

    vec<mint> p2(n + 1, 1);
    for (int i = 1; i <= n; i++)
        p2[i] = p2[i - 1] * 2;

    vec<vec<mint>> suf(n + 1, vec<mint>(26));
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        suf[i][t[i] - 'a'] += p2[n - 1 - i];
    }

    while (q--) {
        int num;
        string s;
        cin >> num >> s;

        string tot = s0;
        int id = 0;
        while (id < num && len(tot) < len(s))
            tot = tot + t[id++] + tot;

        if (len(tot) < len(s)) {
            cout << "0\n";
            continue;
        }

        mint answer = 0;
        answer += p2[num - id] * count(tot, s);

        // tot = tot + 'a' + tot;

        // int where = len(tot) / 2;
        // for (int i = 0; i < 26; i++, tot[where]++)
        //     answer += (suf[id][i] - suf[num][i]) * count(tot, s, where) / p2[n - num];

        auto s_tot = zFunction(s + '$' + tot);
        auto tot_s = zFunction(tot + '$' + s);

        mint inv = p2[n - num].rev();
        for (int mid = 0; mid < len(s); mid++) {
            if (!(mid == 0 || s_tot.end()[-mid] == mid))
                continue;

            if (!(mid == len(s) - 1 || tot_s.end()[-(len(s) - mid - 1)] == len(s) - 1 - mid))
                continue;

            answer += (suf[id][s[mid] - 'a'] - suf[num][s[mid] - 'a']) * inv;
        }

        cout << answer << '\n';
    }
}