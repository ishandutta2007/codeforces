#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int mx;
int a[maxN];
int n;
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != mx) dp[i] = 0;
        else dp[i] = dp[i - 1] + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}