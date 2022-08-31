#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
string bad = "#hard";
const int maxN = (int)1e5 + 10;
const ll INF = (ll)1e18;
ll dp[maxN][5];
char s[maxN];
int a[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 4; j++) {
            dp[i][j] = INF;
        }
    }
    for (int j = 1; j <= 4; j++) dp[0][j] = 0;
    // ha -> har + r
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 4; j++) {
            if (bad[j] != s[i]) {
                dp[i + 1][j] = dp[i][j];
            }
            else {
                //cout << j << " " << s << " " << i << endl;
                //i - j
                dp[i + 1][j] = min(dp[i][j - 1], dp[i][j] + a[i]);
            }
        }
    }
    cout << dp[n][4];
    return 0;
}