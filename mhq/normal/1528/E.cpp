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
const int maxN = 1e6 + 10;
int dp[maxN];
const int inv2 = (mod + 1) / 2;
const int inv3 = (mod + 1) / 3;
int c2(int x) {
    return mult(x, mult(x + 1, inv2));
}
int c3(int x) {
    return mult(x, mult(x + 1, mult(x + 2, mult(inv3, inv2))));
}
int real2[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    assert(mult(inv3, 3) == 1);
    assert(mult(inv2, 2) == 1);
    int s1 = 0;
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            dp[i] = 1;
        }
        else {
            dp[i] = mult(sub(s1, dp[i - 1]), dp[i - 1]);
            dp[i] = sum(dp[i], c2(dp[i - 1]));
            real2[i] = dp[i];
            dp[i] = sum(dp[i], dp[i - 1]);
        }
        s1 = sum(s1, dp[i]);
    }
    int ans = c3(dp[n - 1]);
    ans = sum(ans, dp[n]);
    for (int i = 0; i < (n - 1); i++) {
        ans = sum(ans, mult(c2(dp[n - 1]), dp[i]));
    }
    int s = 0;
    for (int x = 0; x < (n - 1); x++) {
        ans = sum(ans, mult(dp[n - 1], mult(dp[x], s)));
        ans = sum(ans, mult(dp[n - 1], c2(dp[x])));
        s = sum(s, dp[x]);
    }
    /*int T = 0;
    for (int x = 0; x < n; x++) {
        for (int y = x; y < n; y++) {
            for (int z = y; z < n; z++) {
                if (z != (n - 1)) continue;
                if (x == y && x == z) {
                    T = sum(T, c3(dp[x]));
                }
                else if (x == y) {
                    T = sum(T, mult(c2(dp[x]), dp[z]));
                }
                else if (y == z) {
                    T = sum(T, mult(dp[x], c2(dp[z])));
                }
                else {
                    T = sum(T, mult(dp[x], mult(dp[y], dp[z])));
                }
            }
        }
    }*/
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = sum(pref[i - 1], real2[i]);
    ans = mult(ans, 2);
    for (int x = 1; x < n - 1; x++) {
        ans = sum(ans, mult(real2[x], pref[n - x - 1]));
    }
    ans = sub(ans, 1);
    cout << ans << '\n';
    return 0;
}