#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 2000;
bitset<N> basis[N];
bitset<N> used[N];

void add(bitset<N> vec, int id) {
    bitset<N> mask;
    mask[id] = 1;
    for (int i = 0; i < N; i++) {
        if (!vec[i]) continue;
        if (used[i].any()) {
            vec ^= basis[i];
            mask ^= used[i];
        } else {
            basis[i] = vec;
            used[i] = mask;
            return;
        }
    }
}

bitset<N> get(bitset<N> vec) {
    bitset<N> res;
    for (int i = 0; i < N; i++) {
        if (!vec[i]) continue;
        if (used[i].any()) {
            vec ^= basis[i];
            res ^= used[i];
        } else {
            res.reset();
            break;
        }
    }
    return res;
}

#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
using ui64 = uint64_t;

ui64 pw10[19];
ui64 repr[N / 18 + 1];

bitset<N> string_to_bin(string s) {
    forn(i, N / 18 + 1) repr[i] = 0;
    reverse(all(s));
    forn(i, s.size()) repr[i / 18] += ui64(s[i] - '0') * pw10[i % 18];
    __uint128_t b64 = __uint128_t(1) << 64;
    bitset<N> res;
    forn(t, N / 64 + 1) {
        __uint128_t x = 0;
        ford(i, N / 18 + 1) {
            x = x * pw10[18] + repr[i];
            repr[i] = x / b64;
            x %= b64;
        }
        forn(j, 64) {
            int p = t * 64 + j;
            if (p < N) res[p] = (x >> j) & 1;
        }
    }
    return res;
}

void solve() {
    pw10[0] = 1;
    for (int i = 1; i < 19; i++) {
        pw10[i] = pw10[i - 1] * 10;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        auto vec = string_to_bin(s);

        auto res = get(vec);
        cout << res.count() << ' ';
        for (int i = 0; i < N; i++) {
            if (res[i]) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        add(vec, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}