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
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN  = 1e5 + 10;
int mob[maxN];
int lp[maxN];
int l[maxN], r[maxN];
int L[maxN], R[maxN];
int dp[maxN];
int ndp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) lp[j] = i;
        }
    }
    mob[1] = 1;
    for (int i = 2; i < maxN; i++) {
        int p = lp[i];
        if ((i / p) % p == 0) mob[i] = 0;
        else mob[i] = sub(0, mob[i / p]);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    int ways = 0;
    for (int d = 1; d <= m; d++) {
        bool ok = true;
        int cur_m = m / d;
        for (int i = 1; i <= n; i++) {
            L[i] = (l[i] + d - 1) / d;
            R[i] = r[i] / d;
            if (L[i] > R[i]) {
                ok = false;
                break;
            }
            cur_m -= L[i];
            R[i] -= L[i];
        }
        if (cur_m < 0 || !ok) {
            continue;
        }
        for (int z = 0; z <= cur_m; z++) {
            dp[z] = 0;
            ndp[z] = 0;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int s = 0;
            for (int p = 0; p <= cur_m; p++) {
                s = sum(s, dp[p]);
                if (s - R[i] - 1 >= 0) s = sub(s, dp[p - R[i] - 1]);
                ndp[p] = s;
            }
            for (int p = 0; p <= cur_m; p++) {
                dp[p] = ndp[p];
                ndp[p] = 0;
            }
        }
        int ans = 0;
        for (int p = 0; p <= cur_m; p++) ans = sum(ans, dp[p]);
        ways = sum(ways, mult(mob[d], ans));
    }
    cout << ways;
    return 0;
}