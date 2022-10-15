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
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> pos, neg;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b >= 0) {
            pos.emplace_back(a, b);
        } else {
            neg.emplace_back(a, b);
        }
    }
    sort(pos.begin(), pos.end());
    int ans = 0;
    for (auto [a, b] : pos) {
        if (r >= a) {
            r += b;
            ans++;
        }
    }
    sort(neg.begin(), neg.end(), [](const auto& f, const auto& s) {
        return f.first + f.second > s.first + s.second;
    });
    const int N = 60000;
    vector<int> dp(N + 1, -1);
    dp[r] = 0;
    for (auto [a, b] : neg) {
        for (int i = -b; i <= N; i++) {
            if (dp[i] == -1 || i < a) continue;
            dp[i + b] = max(dp[i + b], dp[i] + 1);
        }
    }
    cout << ans + *max_element(dp.begin(), dp.end()) << endl;
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