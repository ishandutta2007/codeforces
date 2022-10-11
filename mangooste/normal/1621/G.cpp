#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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
        return *this *= x.inv();
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
        mint prev = *this;
        value++;
        if (value == mod)
            value = 0;

        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1)
            value = mod - 1;

        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    template<typename T>
    explicit operator T() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        in >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream& operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    auto values = a;
    sort(all(values));
    values.resize(unique(all(values)) - values.begin());
    for (auto &x : a) x = lower_bound(all(values), x) - values.begin();

    struct binary_index_tree {
        int n;
        vector<mint> bit;

        binary_index_tree(int n) : n(n), bit(n + 1) {}

        void add(int pos, mint x) {
            for (pos++; pos <= n; pos += pos & -pos) {
                bit[pos] += x;
            }
        }

        mint query(int pref) {
            mint tot = 0;
            for (pref++; pref; pref -= pref & -pref) {
                tot += bit[pref];
            }
            return tot;
        }

        mint query(int l, int r) {
            return query(r - 1) - query(l - 1);
        }
    };
    
    vector<mint> dp_left(n), dp_right(n);
    for (int rot : {0, 1}) {
        auto &cur = rot == 0 ? dp_left : dp_right;
        binary_index_tree bit(len(values));
        for (int i = 0; i < n; i++) {
            cur[i] = 1 + bit.query(0, a[i]);
            bit.add(a[i], cur[i]);
        }

        reverse(all(a));
        for (auto &x : a) x = len(values) - 1 - x;
    }
    reverse(all(dp_right));

    vector<int> st;
    binary_index_tree bit(len(values));
    mint ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        int pos = int(upper_bound(all(st), a[i]) - st.begin()) - 1;
        if (pos == len(st) - 1) {
            if (len(st) > 0 && st.back() == a[i]) continue;
            st.push_back(a[i]);
            bit.add(a[i], 1);
            continue;
        }

        mint cur_bad = bit.query(a[i] + 1, st[pos + 1]) + 1;
        bit.add(a[i], cur_bad);
        ans += dp_left[i] * (dp_right[i] - cur_bad);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}