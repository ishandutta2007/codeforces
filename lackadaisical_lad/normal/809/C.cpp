#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
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

const int M = 32;
ll dp[M][2][2][2];
ll cnt[M][2][2][2];

ll count(ll x, ll y, ll K) {
    for (int i = 0; i < M; i++) {
        for (int fx = 0; fx < 2; fx++) for (int fy = 0; fy < 2; fy++) for (int fk = 0; fk < 2; fk++) {
            cnt[i][fx][fy][fk] = dp[i][fx][fy][fk] = 0;
        }
    }
    cnt[0][1][1][1] = 1;
    for (int pref = 1; pref < M; pref++) {
        int bit = M - pref - 1;
        int bx = x >> bit & 1;
        int by = y >> bit & 1;
        int bk = K >> bit & 1;
        for (int fx = 0; fx < 2; fx++) for (int fy = 0; fy < 2; fy++) for (int fk = 0; fk < 2; fk++) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    int k = i ^ j;
                    if (fx && i > bx || fy && j > by || fk && k > bk) continue;
                    int ffx = fx && i == bx;
                    int ffy = fy && j == by;
                    int ffk = fk && k == bk;
                    (cnt[pref][ffx][ffy][ffk] += cnt[pref - 1][fx][fy][fk]) %= MOD;
                    (dp[pref][ffx][ffy][ffk] += cnt[pref - 1][fx][fy][fk] * k + dp[pref - 1][fx][fy][fk] * 2) %= MOD;
                }
            }
        }
    }
    ll res = cnt[M - 1][0][0][0] + dp[M - 1][0][0][0];
    return res % MOD;
}

void solve() {
    ll x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;

    // 0..x 0..y sum all (i ^ j + 1) <= k
    ll ans = count(x2, y2, k) - count(x1 - 1, y2, k) - count(x2, y1 - 1, k) + count(x1 - 1, y1 - 1, k);
    ans = ans % MOD + MOD;
    cout << ans % MOD << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}