#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MxN = 1e5;
int t, n, c[MxN], a[MxN], b[MxN];
ll dp[MxN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    dp[0]=0;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i]==b[i]) dp[i]=c[i]+1;
        else dp[i] = max(dp[i-1] - abs(a[i]-b[i]), (ll)abs(b[i]-a[i])) + c[i] + 1;
        if (dp[i]>ans) ans=dp[i];
    }
    cout << ans << '\n';
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}