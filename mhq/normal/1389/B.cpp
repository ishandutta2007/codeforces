#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
ll dp[maxN][6][2];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k, z;
        cin >> n >> k >> z;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= z; j++) {
                for (int c = 0; c < 2; c++) {
                    dp[i][j][c] = -1e18;
                }
            }
        }
        dp[0][0][0] = a[1];
        for (int i = 0; i < k; i++) {
            for (int le = 0; le <= z && le <= i; le++) {
                for (int c = 0; c < 2; c++) {
                    if (dp[i][le][c] < 0) continue;
                    int pos = 1 + ((i - le) - le);
                    if (pos < 1 || pos > n) continue;
                    if (pos < n) {
                        dp[i + 1][le][0] = max(dp[i + 1][le][0], dp[i][le][c] + a[pos + 1]);
                    }
                    if (pos > 1 && le < z && c == 0) {
                        dp[i + 1][le + 1][1] = max(dp[i + 1][le + 1][1], dp[i][le][c] + a[pos - 1]);
                    }
                }
            }
        }
        ll mx = 0;
        for (int le = 0; le <= z; le++) {
            mx = max(mx, dp[k][le][0]);
            mx = max(mx, dp[k][le][1]);
        }
        cout << mx << '\n';
    }
    return 0;
}