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

const vector<int> prec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

struct segtree {
    struct node {
        mint dp[2][2];
        int left, right;
        int length;

        node() {}
        node(int val) : left(val), right(val), length(1) {
            for (auto i : {0, 1})
                for (auto j : {0, 1})
                    dp[i][j] = 1;

            dp[0][0] = prec[val];
            dp[1][1] = 0;
        }
    };

    inline node merge(const node &a, const node &b) {
        node res;
        res.left = a.left;
        res.right = b.right;
        res.length = a.length + b.length;

        for (auto i : {0, 1})
            for (auto j : {0, 1}) {
                res.dp[i][j] = a.dp[i][0] * b.dp[0][j];
                if ((i && a.length == 1) || (j && b.length == 1) || a.right != 1)
                    continue;

                res.dp[i][j] += a.dp[i][1] * b.dp[1][j] * prec[a.right * 10 + b.left];
            }

        return res;
    }

    int n;
    vector<node> tree;

    segtree(vector<int> a) : n(len(a)), tree(4 * n) {
        build(1, 0, n, a);
    }

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vr - vl == 1) {
            tree[v] = node(a[vl]);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, a);
        build(v << 1 | 1, vm, vr, a);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    void update(int pos, int val) {
        update(1, 0, n, pos, val);
    }

    void update(int v, int vl, int vr, int pos, int val) {
        if (vr - vl == 1) {
            tree[v] = node(val);
            return;
        }

        int vm = (vl + vr) >> 1;
        (pos < vm ? update(v << 1, vl, vm, pos, val) : update(v << 1 | 1, vm, vr, pos, val));
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    inline mint answer() {
        return tree[1].dp[0][0];
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> init(n);
    for (auto &x : init) {
        char c;
        cin >> c;
        x = c - '0';
    }

    segtree tree(init);
    while (q--) {
        int pos; 
        char c;
        cin >> pos >> c;
        tree.update(pos - 1, c - '0');
        cout << tree.answer() << '\n';
    }
}