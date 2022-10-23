#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2e5 + 10;
ll a[maxN];
ll dp[maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 0; j < 2; j++) {
                dp[i][j] = -1e18;
            }
        }
        dp[1][0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int was = 0; was < 2; was++) {
                for (int will = 0; will < 2; will++) {
                    if ((!was && s[i - 2] == '1') || (will && s[i - 1] == '1')) {
                        dp[i][will] = max(dp[i][will], dp[i - 1][was] + a[i - 1]);
                    }
                    else {
                        dp[i][will] = max(dp[i][will], dp[i - 1][was]);
                    }
                }
            }
        }
        ll ans = max(dp[n][0] + a[n] * (s[n - 1] == '1'), dp[n][1]);
        cout << ans << '\n';
    }
    return 0;
}