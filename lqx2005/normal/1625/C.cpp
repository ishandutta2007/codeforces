#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 500 + 10;
int n, l, k, a[N], d[N];
int dp[N][N];
void solve() {
    cin >> n >> l >> k;
    for(int i = 1; i <= n; i++) cin >> d[i];
    d[n + 1] = l;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n + 1; j++) {
            for(int k = 1; k <= n + 1; k++) {
                dp[j][k + 1] = min(dp[j][k + 1], dp[i][k] + (d[j] - d[i]) * a[i]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i = n + 1 - k; i <= n + 1; i++) {
        ans = min(ans, dp[n + 1][i]);
    }
    cout << ans << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    // int t;
    // for(cin >> t; t--; solve());
    return 0;
}