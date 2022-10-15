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

void solve() {
    ll n, s;
    cin >> n >> s;
    if (s < n + n - 1 || s > n * (n + 1) / 2) {
        cout << "No\n";
        return;
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<ll> cnt(n);
        cnt[0] = 1;
        ll m = n - 1;
        ll sum = 1;
        for (int i = 1; i < n; i++) {
            cnt[i] = min(cnt[i - 1] * mid, m);
            m -= cnt[i];
            sum += (i + 1) * cnt[i];
        }
        if (sum > s) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << "Yes\n";
    vector<ll> cnt(n);
    cnt[0] = 1;
    ll m = n - 1;
    s--;
    for (int i = 1; i < n && m; i++) {
        while (cnt[i] < cnt[i - 1] * r && cnt[i] < m && s - (cnt[i] + 1) * (i + 1) - (m - cnt[i] - 1) * (i + 2 + i + m - cnt[i]) / 2 <= 0) {
            cnt[i]++;
        }
        m -= cnt[i];
        s -= cnt[i] * (i + 1);
    }
    vector<int> p(n + 1);
    vector<vector<int>> layers(n);
    layers[0].push_back(1);
    int cur = 2;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            layers[i].push_back(cur); 
            p[cur++] = layers[i - 1][j / r];
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
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