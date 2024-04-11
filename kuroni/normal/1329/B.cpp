#include <bits/stdc++.h>
using namespace std;

const int N = 100005, LG = 30;

int n, t, d, m;
long long dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> d >> m;
        dp[0] = 1;
        long long ans = 1;
        for (int i = 1; (1 << i) <= d; i++) {
            int cnt = min((1 << i), d - (1 << i) + 1) % m;
            dp[i] = (ans + 1) * cnt % m;
            (ans += dp[i]) %= m;
        }
        cout << ans % m << '\n';
    }
}