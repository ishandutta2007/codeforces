#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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

int main() {
    using namespace std;
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    int n = len(s);

    vector<int> balance(n + 1);
    for (int i = 0; i < n; i++) {
        balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
    }
    vector<int> nxt(n, -1), last(2 * n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') nxt[i] = last[balance[i] + n];
        last[balance[i + 1] + n] = i + 1;
    }

    const int LG = __lg(n + 1) + 1;
    vector jump(n + 1, vector<int>(LG, -1));
    vector hsh(n + 1, vector<hash_t<2>>(LG));
    vector<int> par(n + 1, -1);
    vector<char> type(n + 1, '?');

    for (int i = n - 1; i >= 0; i--) {
        par[i] = i + 1;
        type[i] = s[i];

        jump[i][0] = i + 1;
        hsh[i][0] = hash_t<2>(s[i]);

        int cur = i + 1;
        for (int level = 1; level < LG; level++) {
            int new_cur = jump[cur][level - 1];
            if (new_cur == -1) break;
            hsh[i][level] = hsh[i][level - 1] + hsh[cur][level - 1];
            cur = new_cur;
            jump[i][level] = cur;
        }
        if (nxt[i] == -1) continue;

        int v1 = i, v2 = nxt[i];
        for (int level = LG - 1; level >= 0; level--) {
            int new_v1 = jump[v1][level];
            int new_v2 = jump[v2][level];
            if (new_v1 == -1 || new_v2 == -1) continue;
            if (hsh[v1][level] == hsh[v2][level]) {
                v1 = new_v1;
                v2 = new_v2;
            }
        }

        if (par[v1] == -1) continue;
        if (par[v2] == -1 || type[v1] > type[v2]) {
            par[i] = par[nxt[i]];
            type[i] = type[nxt[i]];
            jump[i] = jump[nxt[i]];
            hsh[i] = hsh[nxt[i]];
        }
    }

    string ans;
    for (int i = 0;; i = par[i]) {
        if (type[i] == '?') break;
        ans += type[i];
    }
    cout << ans << '\n';
}