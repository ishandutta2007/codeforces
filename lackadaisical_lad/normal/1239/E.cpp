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

const int A = 50000;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    int tot = 0;
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
        tot += a[i];
    }
    sort(a.begin(), a.end());
    int ans = a[0] + a[1];
    tot -= a[0] + a[1];
    int need = n - 1;
    vector<vector<int>> dp(need + 1, vector<int>(A * need + 1));
    vector<vector<int>> way(need + 1, vector<int>(A * need + 1));
    dp[0][0] = 1;
    for (int i = 2; i < n * 2; i++) {
        for (int j = need; j > 0; j--) {
            for (int k = A * need; k >= a[i]; k--) {
                if (!dp[j][k] && dp[j - 1][k - a[i]]) {
                    dp[j][k] = 1;
                    way[j][k] = i;
                }
            }
        }
    }
    int best = -1;
    for (int i = tot / 2; i >= 0; i--) {
        if (dp[need][i]) {
            best = i;
            break;
        }
    }
    vector<int> used(n * 2);
    for (int i = need; i > 0; i--) {
        used[way[i][best]] = 1;
        best -= a[way[i][best]];
    }
    cout << a[0] << ' ';
    for (int i = 2; i < n * 2; i++) {
        if (used[i]) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
    for (int i = n * 2 - 1; i >= 2; i--) {
        if (!used[i]) {
            cout << a[i] << ' ';
        }
    }
    cout << a[1] << '\n';
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