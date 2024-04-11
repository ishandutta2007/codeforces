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
constexpr int MOD = 998'244'353;
using mint = mval<MOD>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<mint> coeff(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        coeff[i] = mint(100) / p;
    }

    vector<mint> pref_prod(n + 1, 1);
    vector<mint> ipref_prod(n + 1, 1);
    for (int i = 0; i < n; i++) {
        pref_prod[i + 1] = pref_prod[i] * coeff[i];
        ipref_prod[i + 1] = pref_prod[i + 1].rev();
    }

    vector<mint> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = (pref[i] + 1) * coeff[i];

    auto get_answer = [&](int l, int r) {
        return pref[r] - pref[l] * pref_prod[r] * ipref_prod[l];
    };

    mint answer = get_answer(0, n);
    set<int> st{0, n};

    while (q--) {
        int pos;
        cin >> pos, pos--;

        int coeff = 1;
        if (!st.count(pos)) {
            st.insert(pos);
            coeff = -1;
        }

        auto it = st.find(pos);
        mint delta = 0;
        delta -= get_answer(*prev(it), pos);
        delta -= get_answer(pos, *next(it));
        delta += get_answer(*prev(it), *next(it));
        if (coeff == 1)
            st.erase(it);

        answer += delta * coeff;
        cout << answer << '\n';
    }
}