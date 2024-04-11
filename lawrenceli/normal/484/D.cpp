#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000100;

int n, a[MAXN];
ll m1, m2;
ll dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    dp[0] = 0;
    m1 = -a[1], m2 = a[1];
    for (int i=1; i<=n; i++) {
        dp[i] = max(a[i]+m1, -a[i]+m2);
        m1 = max(m1, dp[i]-a[i+1]);
        m2 = max(m2, dp[i]+a[i+1]);
    }

    cout << dp[n] << '\n';
    return 0;
}