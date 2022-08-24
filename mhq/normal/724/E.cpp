#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e4 + 100;
ll dp[maxN];
ll ndp[maxN];
ll p[maxN], s[maxN], c;
int n;
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
        ndp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i + 1 <= n; i++) {
        for (int cnt = 0; cnt <= i; cnt++) {
            ndp[cnt] = min(ndp[cnt], dp[cnt] + c * cnt + p[i + 1]);
            ndp[cnt + 1] = min(ndp[cnt + 1], dp[cnt] + s[i + 1]);
        }
        for (int cnt = 0; cnt <= i + 1; cnt++) {
            dp[cnt] = ndp[cnt];
            ndp[cnt] = INF;
        }
    }
    ll mn = INF;
    for (int i = 0; i <= n; i++) mn = min(mn, dp[i]);
    cout << mn;
    return 0;
}