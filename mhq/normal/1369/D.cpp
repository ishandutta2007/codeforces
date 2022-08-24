#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2e6 + 10;
pair < int, int > dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    dp[1] = make_pair(0, 1);
    dp[2] = make_pair(0, 1);
    for (int i = 3; i < maxN; i++) {
        int ans = sum(dp[i - 1].first, sum(dp[i - 2].first, dp[i - 2].first));
        if (dp[i - 1].second && dp[i - 2].second) {
            ans = sum(ans, 1);
            dp[i].second = 0;
        }
        else {
            dp[i].second = 1;
        }
        dp[i].first = ans;
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        cout << mult(4, dp[n].first) << '\n';
    }
    return 0;
}