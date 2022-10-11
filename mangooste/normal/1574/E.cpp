#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template <typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template <int mod>
struct static_modular_int {
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template <typename T>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    template <typename T>
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

    mint &operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint &operator+=(const mint &x) {
        value += x.value;
        if (value >= mod)
            value -= mod;

        return *this;
    }

    mint &operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += mod;

        return *this;
    }

    mint &operator*=(const mint &x) {
        value = (long long)value * x.value % mod;
        return *this;
    }

    mint &operator/=(const mint &x) {
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

    mint &operator++() {
        ++value;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint &operator--() {
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

    template <typename T>
    explicit operator T() {
        return value;
    }

    friend istream &operator>>(istream &in, mint &x) {
        std::string s;
        in >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream &operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    struct solver {
        vector<array<int, 2>> cnt;
        int bad, tot;

        solver(int n) : cnt(n), bad(0), tot(n) {}

        void add(int x, int y, int t) {
            y &= 1;
            y ^= t;
            bad -= cnt[x][0] > 0 && cnt[x][1] > 0;
            tot -= cnt[x][0] == 0 && cnt[x][1] == 0;
            cnt[x][y]++;
            bad += cnt[x][0] > 0 && cnt[x][1] > 0;
        }

        void remove(int x, int y, int t) {
            y &= 1;
            y ^= t;
            bad -= cnt[x][0] > 0 && cnt[x][1] > 0;
            cnt[x][y]--;
            tot += cnt[x][0] == 0 && cnt[x][1] == 0;
            bad += cnt[x][0] > 0 && cnt[x][1] > 0;
        }

        mint solve() const {
            if (bad) return 0;
            return mint(2).power(tot);
        }
    } sx(n), sy(m);

    map<pair<int, int>, int> mp;
    array<int, 2> bad{0, 0};

    auto remove = [&](int x, int y) {
        if (!mp.count({x, y})) return;
        int t = mp[{x, y}];
        sx.remove(x, y, t);
        sy.remove(y, x, t);
        for (int i : {0, 1}) {
            bad[i] -= (x + y + t) % 2 != i;
        }
        mp.erase({x, y});
    };

    while (k--) {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;

        if (t == -1) {
            remove(x, y);
        } else {
            remove(x, y);
            mp[{x, y}] = t;
            sx.add(x, y, t);
            sy.add(y, x, t);
            for (int i : {0, 1}) {
                bad[i] += (x + y + t) % 2 != i;
            }
        }

        mint ans = sx.solve() + sy.solve();
        for (int i : {0, 1}) {
            if (bad[i] == 0) ans--;
        }
        cout << ans << '\n';
    }
}