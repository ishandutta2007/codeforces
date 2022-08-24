#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
ll dp[maxN][3][2][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        for (int sum = 0; sum < 3; sum++) {
            for (int fl = 0; fl < 2; fl++) {
                for (int last = 0; last < 2; last++) {
                    dp[i][sum][fl][last] = -1e18;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int sum = 0; sum < 3; sum++) {
            for (int fl = 0; fl < 2; fl++) {
                for (int last = 0; last < 2; last++) {
                    for (int who = 0; who < 2; who++) {
                        int nfl = fl | ((i > 0) && (last == who));
                        int nsum = (sum + (who == 1 ? 1 : -1));
                        nsum %= 3;
                        if (nsum < 0) nsum += 3;
                        ll nd = dp[i][sum][fl][last] + ((who == 1 ? 1 : -1) * a[i + 1]);
                        dp[i + 1][nsum][nfl][who] = max(dp[i + 1][nsum][nfl][who], nd);
                    }
                }
            }
        }
    }
    cout << max(dp[n][1][1][0], dp[n][1][1][1]);
    return 0;
}