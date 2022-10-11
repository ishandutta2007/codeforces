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
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template<int mod>
struct static_modular_int {
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template<typename T>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    template<typename T>
    mint power(T degree) const {
        degree = normalize(degree, mod - 1);
        mint prod = 1;
        mint a = *this;

        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(-1);
    }

    mint& operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint &x) {
        value += x.value;
        if (value >= mod)
            value -= mod;

        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += mod;

        return *this;
    }

    mint& operator*=(const mint &x) {
        value = (long long) value * x.value % mod;
        return *this;
    }

    mint& operator/=(const mint &x) {
        value = (long long) value * x.inv().value % mod;
        return *this;
    }

    friend mint operator+(const mint &x, const mint &y) {
        return mint(x) += y;
    }

    friend mint operator-(const mint &x, const mint &y) {
        return mint(x) -= y;
    }

    friend mint operator*(const mint &x, const mint &y) {
        return mint(x) *= y;
    }

    friend mint operator/(const mint &x, const mint &y) {
        return mint(x) /= y;
    }

    mint& operator++() {
        ++value;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    mint operator++(int) {
        value++;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint operator--(int) {
        value--;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    explicit operator int() {
        return value;
    }

    explicit operator long long() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        cin >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream& operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

namespace factorials {
    std::vector<mint> fact;
    std::vector<mint> ifact;
    std::vector<mint> inv;

    void init(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        ifact.resize(n + 1);
        ifact.back() = fact.back().inv();
        for (int i = n; i > 0; i--)
            ifact[i - 1] = ifact[i] * i;

        inv.resize(n + 1);
        for (int i = 1; i <= n; i++)
            inv[i] = ifact[i] * fact[i - 1];
    }

    mint choose(int n, int k) {
        if (n < k || k < 0 || n < 0)
            return 0;

        return fact[n] * ifact[k] * ifact[n - k];
    }
} // namespace factorials

using factorials::fact;
using factorials::ifact;
using factorials::inv;
using factorials::choose;

struct ordered_set {
    static constexpr int N = 1 << 18;
    int tree[2 * N], mod[2 * N];

    ordered_set() {
        fill(all(mod), -1);
    }

    void push(int v, int vl, int vr) {
        if (mod[v] == -1)
            return;

        if (vr - vl > 1)
            mod[v << 1] = mod[v << 1 | 1] = mod[v];

        tree[v] = (vr - vl) * mod[v];
        mod[v] = -1;
    }

    void update(int l, int r, int value) {
        update(1, 0, N, l, r, value);
    }

    void update(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            mod[v] = value;
            push(v, vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        update(v << 1, vl, vm, l, r, value);
        update(v << 1 | 1, vm, vr, l, r, value);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }

    int find(int pos) {
        return find(1, 0, N, pos);
    }

    int find(int v, int vl, int vr, int pos) {
        push(v, vl, vr);
        if (tree[v] <= pos)
            return -1;

        if (vr - vl == 1)
            return vl;

        int vm = (vl + vr) >> 1;
        int result = find(v << 1, vl, vm, pos);
        if (result == -1)
            result = find(v << 1 | 1, vm, vr, pos - tree[v << 1]);

        assert(result != -1);
        return result;
    }
} st;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> events(m);
    for (auto &[i, j] : events) {
        cin >> i >> j;
        i--, j--;
    }


    st.update(0, n, 1);
    vector<pair<int, int>> who;
    reverse(all(events));

    for (auto &[i, j] : events) {
        int pos = st.find(j);
        who.emplace_back(pos, i);
        st.update(pos, pos + 1, 0);
    }
    sort(all(who));

    int cnt = n - 1;
    for (int i = 0; i < len(who); i++)
        if (who[i].first != n - 1 && (i == len(who) - 1 || who[i + 1].first != who[i].first + 1 || who[i + 1].second < who[i].second))
            cnt--;

    cout << choose(n + cnt, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    factorials::init(1e6);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}