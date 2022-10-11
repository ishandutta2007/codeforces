#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<int SZ>
struct hash_t {
    static bool initialized;
    static int MOD[SZ], BASE[SZ];
    static std::vector<int> POWER[SZ];

    static void initialize() {
        assert(!initialized);
        initialized = true;
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        for (int i = 0; i < SZ; i++) {
            auto is_prime = [&](int x) {
                for (int i = 2; i * i <= x; i++)
                    if (x % i == 0)
                        return false;

                return true;
            };

            MOD[i] = int(8e5) + rng() % int(2e8 + 228);
            while (!is_prime(MOD[i]))
                MOD[i]++;

            BASE[i] = rng() % MOD[i];
            if (!(BASE[i] & 1))
                BASE[i]++;

            POWER[i].push_back(1);
        }
    }

    static void ensure(int n) {
        assert(initialized);
        if (int(POWER[0].size()) >= n)
            return;

        for (int i = 0; i < SZ; i++)
            for (int j = POWER[i].size(); j < n; j++)
                POWER[i].push_back(int64_t(POWER[i].back()) * BASE[i] % MOD[i]);
    }

    int length;
    std::array<int, SZ> h;

    hash_t() : length(0) {
        h.fill(0);
        if (!initialized)
            initialize();
    }

    template<typename T>
    hash_t(const T &value, int length = 1) : length(length) {
        if (!initialized)
            initialize();

        ensure(length);
        h.fill(0);
        for (int i = 0; i < SZ; i++)
            for (int j = 0; j < length; j++) {
                h[i] += int64_t(value + 1) * POWER[i][j] % MOD[i];
                if (h[i] >= MOD[i])
                    h[i] -= MOD[i];
            }
    }

    hash_t<SZ>& operator+=(const hash_t<SZ> &x) {
        assert(initialized);
        ensure(x.length + 1);
        for (int i = 0; i < SZ; i++)
            h[i] = (int64_t(h[i]) * POWER[i][x.length] + x.h[i]) % MOD[i];

        length += x.length;
        return *this;
    }

    hash_t<SZ>& operator-=(const hash_t<SZ> &x) {
        assert(initialized);
        assert(x.length <= length);
        ensure(length - x.length + 1);
        for (int i = 0; i < SZ; i++) {
            h[i] -= int64_t(x.h[i]) * POWER[i][length - x.length] % MOD[i];
            if (h[i] < 0)
                h[i] += MOD[i];
        }
        length -= x.length;
        return *this;
    }

    bool operator==(const hash_t<SZ> &x) const {
        if (length != x.length)
            return false;

        return h == x.h;
    }

    bool operator<(const hash_t<SZ> &x) const {
        if (length != x.length)
            return length < x.length;

        return h < x.h;
    }

    friend hash_t<SZ> operator+(const hash_t<SZ> &left, const hash_t<SZ> &right) {
        return hash_t<SZ>(left) += right;
    }

    friend hash_t<SZ> operator-(const hash_t<SZ> &left, const hash_t<SZ> &right) {
        return hash_t<SZ>(left) -= right;
    }
};

template<int SZ> bool hash_t<SZ>::initialized = false;
template<int SZ> int hash_t<SZ>::MOD[SZ] = {};
template<int SZ> int hash_t<SZ>::BASE[SZ] = {};
template<int SZ> std::vector<int> hash_t<SZ>::POWER[SZ] = {};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    using my_hash = hash_t<2>;
    vector<my_hash> pref(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + my_hash(s[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = my_hash(s[i]) + suf[i + 1];
    }

    vector<my_hash> ipref(n + 1), isuf(n + 1);
    for (int i = 0; i < n; i++) {
        ipref[i + 1] = my_hash(s[i]) + ipref[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        isuf[i] = isuf[i + 1] + my_hash(s[i]);
    }

    int ans = 0;
    for (int pos = 0; pos < n; pos++) {
        ans += pref[pos] + suf[pos + 1] == isuf[pos + 1] + ipref[pos];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}