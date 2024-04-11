#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 2e6 + 10;
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            dp[j] = sum(dp[j], 1);
        }
    }
    int pr = 0;
    for (int j = 1; j <= n; j++) {
        dp[j] = sum(dp[j], pr);
        pr = sum(pr, dp[j]);
    }
    cout << dp[n] << '\n';
    return 0;
}