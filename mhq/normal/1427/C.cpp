#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int r, n;
const int maxN = 1e5 + 10;
int dp[maxN];
int x[maxN], y[maxN];
int t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> r >> n;
    dp[0] = 0;
    x[0] = y[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = -1e9;
        for (int j = i - 1; j >= 0 && j >= i - 4 * r - 5; j--) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int mx = *max_element(dp, dp + n + 1);
    cout << mx;
    return 0;
}