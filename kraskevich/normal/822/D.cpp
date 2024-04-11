#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 5000 * 1000 + 2;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = (ll)1e18;

ll dp[N];

ll func(ll i) {
    return i * (i - 1) / 2;
}

void init() {
    fill(dp, dp + N, INF);
    dp[1] = 0;
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i], func(i));
        int sz = 2;
        for (int j = 2 * i; j < N; j += i, sz++) 
            dp[j] = min(dp[j], dp[i] + i * func(sz));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    
    int t, l, r;
    cin >> t >> l >> r;
    ll cur = 1;
    ll ans = 0;
    for (int i = l; i <= r; i++) {
        ans += dp[i] % MOD * cur;
        ans %= MOD;
        cur *= t;
        cur %= MOD;
    }
    cout << ans << "\n";
}