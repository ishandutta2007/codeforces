#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int dp[maxN][maxN];
int a[maxN];
int mx[maxN][maxN];
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
        for (int l = 1; l <= n; l++) {
            set<int> s;
            for (int r = l; r <= n; r++) {
                s.insert(a[r]);
                mx[l][r] = 0;
                while (s.count(mx[l][r])) mx[l][r]++;
            }
        }
        int ans = 0;
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = mx[l][r] + 1;
                for (int k = l; k < r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + mx[k + 1][r] + 1);
                }
                ans += dp[l][r];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}