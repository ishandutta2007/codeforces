#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int dp[maxN];
int e[maxN];
int pref_dp[maxN];
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
            cin >> e[i];
        }
        sort(e + 1, e + n + 1);
        dp[0] = 0;
        pref_dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= e[i]) {
                dp[i] = pref_dp[i - e[i]] + 1;
            }
            else {
                dp[i] = -(int)1e9;
            }
            pref_dp[i] = max(pref_dp[i - 1], dp[i]);
        }
        cout << pref_dp[n] << '\n';
    }
    return 0;
}