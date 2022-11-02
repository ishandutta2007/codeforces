#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = int(1e9);
const int D1 = 90;
const int D2 = 1440;
const int C0 = 20;
const int C1 = 50;
const int C2 = 120;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + C0;
        for (int p = i - 1; p >= 0; p--) {
            if (t[i] - t[p + 1] >= D2)
                break;
            if (t[i] - t[p + 1] < D1)
                dp[i] = min(dp[i], dp[p] + C1);
            dp[i] = min(dp[i], dp[p] + C2);
        }    
        ll cur = dp[i] - tot;
        cout << cur << "\n";
        tot += cur;
    }
}