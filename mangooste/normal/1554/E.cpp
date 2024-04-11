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

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    inline decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    set<int> possib;
    bool was = false;

    y_combinator([&](auto dfs, int v) -> void {
        if (g[v].empty())
            return;

        bool all_leafs = true;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            all_leafs &= g[u].empty();
        }

        if (all_leafs) {
            set<int> current;
            for (int i = 1; i <= len(g[v]) + (v != 0); i++)
                if (len(g[v]) % i == 0 || (len(g[v]) + (v != 0)) % i == 0)
                    current.insert(i);

            if (!was) {
                was = true;
                possib = current;
            } else {
                set<int> new_possib;
                for (auto x : current)
                    if (possib.count(x))
                        new_possib.insert(x);

                swap(new_possib, possib);
            }
        }
    })(0);
    assert(was);

    vector<mint> answer(n + 1);
    answer[1] = mint(2).power(n - 1);

    vector<int> used(n + 1);
    int timer = 0;
    for (int who = n; who >= 2; who--) {
        if (!possib.count(who))
            continue;

        bool any = false;
        for (int j = who; j <= n; j += who)
            any |= answer[j] != 0;

        if (any)
            continue;

        timer++;
        bool ok = true;

        y_combinator([&](auto dfs, int v) -> void {
            if (g[v].empty())
                return;

            int cnt = 0;
            for (auto u : g[v]) {
                dfs(u);
                if (!ok)
                    return;

                cnt += used[u] != timer;
            }

            if (v != 0 && (cnt + 1) % who == 0) {
                used[v] = timer;
                return;
            }
            if (cnt % who != 0)
                ok = false;
        })(0);
        answer[who] = (ok ? 1 : 0);
    }

    answer[1] -= accumulate(2 + all(answer), mint(0));
    for (int i = 1; i <= n; i++)
        cout << answer[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}