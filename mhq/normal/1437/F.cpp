#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int n;
const int maxN = 5005;
int a[maxN];
int dp[maxN][maxN];
int pref[maxN];
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sm[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int p = 1;
    for (int i = 1; i <= n; i++) {
        while (2 * a[p] <= a[i]) p++;
        pref[i] = p;
        pref[i]--;
        //[1 .. p - 1] good
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        sm[i][0] = sum(sm[i - 1][0], dp[i][0]);
    }

    for (int cnt = 1; cnt <= n; cnt++) {
        for (int i = 1; i <= n; i++) {
            dp[i][cnt] = sm[pref[i]][cnt - 1];
            if (pref[i] >= cnt) dp[i][cnt] = sum(dp[i][cnt], mult(dp[i][cnt - 1], (pref[i] - cnt + 1)));
            sm[i][cnt] = sum(dp[i][cnt], sm[i - 1][cnt]);
        }
    }
    cout << dp[n][n - 1] << '\n';
    return 0;
}