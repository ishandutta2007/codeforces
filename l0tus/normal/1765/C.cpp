#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll n, k, dp[2020][2020], poly[2020], tmp[2020];

ll inv(ll a) {
    ll r = 1, x = MOD - 2;
    while (x) {
        if (x & 1) r = r * a % MOD;
        x /= 2; a = a * a % MOD;
    }
    return r;
}
void addi(ll &v, ll x) { v = (v + x >= MOD) ? v + x - MOD : v + x; }
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k;
    vector<ll> f = { 1 };
    for (int i = 0; i < n; i++) {
        ll x = f.back();
        f.push_back(x * (n - i) % MOD * inv(i + 1) % MOD);
    }
    for (int i = 0; i < n; i++) {
        fill(poly, poly + 2020, 0);
        poly[0] = 1;
        for (int t = 0; t < 4; t++) {
            fill(tmp, tmp + 2020, 0);
            for (int j = 0; j < 2020; j++) if (poly[j]) {
                for (int k = i; k <= n; k++) {
                    addi(tmp[j + k], poly[j] * f[k] % MOD);
                }
            }
            for (int j = 0; j < 2020; j++) poly[j] = tmp[j];
        }
        for (int j = 0; j <= k; j++) {
            dp[i][j] = poly[j];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) {
        dp[i][j] = (dp[i][j] + MOD - dp[i + 1][j]) % MOD;
    }
    ll ans = 0, s = 1;
    for (int i = 1; i <= 4 * n; i++) {
        int sz = min((int)k, i - 1);
        for (int j = 0; j < n; j++) {
            addi(ans, dp[j][sz] * (n - j) % MOD * inv(s * (4 * n - sz) % MOD) % MOD);
        }
        if (i <= k) s = s * (4 * n + 1 - i) % MOD * inv(i) % MOD;
    }
    cout << ans;
}