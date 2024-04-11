#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sub(int a, int b) {
    int s = a - b;
    s %= mod;
    if (s < 0) s += mod;
    return s;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n;
const int maxN = 2e5 + 10;
int x[maxN], y[maxN];
int s[maxN];
int pref[maxN];
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<pair<int,int>> byX;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        int f = lower_bound(x + 1, x + n + 1, y[i]) - x;
        dp[i] = sum(sub(x[i], y[i]), sub(pref[i - 1], pref[f - 1]));
        pref[i] = sum(pref[i - 1], dp[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 1) {
            ans = sum(ans, dp[i]);
        }
    }
    ans = sum(ans, x[n] + 1);
    cout << ans << '\n';

    return 0;
}