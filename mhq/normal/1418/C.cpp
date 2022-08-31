#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int dp[maxN][2];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dp[0][1] = 0;
        dp[0][0] = 1e9;
        for (int i = 1; i <= n; i++) {
            for (int who = 0; who < 2; who++) {
                dp[i][who] = 1e9;
                for (int cnt = 1; cnt <= 2 && cnt <= i; cnt++) {
                    int val = dp[i - cnt][who ^ 1];
                    if (who == 0) {
                        val += a[i];
                        if (cnt == 2) val += a[i - 1];
                    }
                    dp[i][who] = min(dp[i][who], val);
                }
            }
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}