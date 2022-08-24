#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int mod;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 505;
const int SHIFT = (maxN * maxN) / 2 + 2 * maxN;
int dp[maxN * maxN + 5 * maxN + 15];
int ndp[maxN * maxN + 5 * maxN + 15];
int ans[maxN];
int n;
int pref[maxN * maxN + 5 * maxN + 15];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> mod;
    dp[SHIFT] = 1 % mod;
    for (int i = 1; i <= n; i++) {
        ans[i] = mult(i, ans[i - 1]);
        //add i
        int lim = ((i - 1) * (i - 2)) / 2;
        pref[-lim - 1 + SHIFT] = 0;
        for (int z = -lim; z <= lim; z++) {
            pref[z + SHIFT] = sum(pref[z - 1 + SHIFT], dp[z + SHIFT]);
        }
        for (int x = 1; x <= i; x++) {
            for (int y = x + 1; y <= i; y++) {
                if (lim >= y - x + 1) {
                    ans[i] = sum(ans[i], sub(pref[lim + SHIFT], pref[max(y - x, -lim - 1) + SHIFT]));
                }
            }
        }
        //add n
        int nlim = lim + i - 1;
        memset(ndp, 0, sizeof ndp);
        for (int a = -lim; a <= lim; a++) {
            ndp[a + SHIFT] = sum(ndp[a + SHIFT], dp[a + SHIFT]);
            ndp[a + SHIFT + i] = sub(ndp[a + SHIFT + i], dp[a + SHIFT]);
        }
        for (int x = -nlim + 1; x <= nlim; x++) {
            ndp[x + SHIFT] = sum(ndp[x + SHIFT], ndp[x - 1 + SHIFT]);
        }
        for (int x = -nlim; x <= nlim; x++) {
            dp[x + SHIFT] = ndp[x + SHIFT];
            ndp[x + SHIFT] = 0;
        }
        memset(ndp, 0, sizeof ndp);
        for (int a = -nlim; a <= nlim; a++) {
            ndp[a + 1 + SHIFT] = sub(ndp[a + 1 + SHIFT], dp[a + SHIFT]);
            ndp[a + SHIFT - i + 1] = sum(ndp[a + SHIFT - i + 1], dp[a + SHIFT]);
        }
        for (int x = -nlim + 1; x <= nlim; x++) {
            ndp[x + SHIFT] = sum(ndp[x + SHIFT], ndp[x - 1 + SHIFT]);
        }
        for (int x = -nlim; x <= nlim; x++) {
            dp[x + SHIFT] = ndp[x + SHIFT];
            ndp[x + SHIFT] = 0;
        }
    }
    cout << ans[n] % mod << '\n';
    return 0;
}