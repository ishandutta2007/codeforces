#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
int n, k;
int len;
const int maxN = (int)1e5 + 10;
const int maxK = 105;
int dp[maxN][maxK];
int sum_pref[maxN];
int a[maxN];
int f[maxN][maxK];
int all[maxN];
bool can(int l, int r, int color) {
    return (all[r] - all[l - 1] == f[r][color] - f[l - 1][color]);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> k >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int color = 1; color <= k; color++) {
            f[i][color] = f[i - 1][color];
            f[i][color] += (color == a[i]);
        }
        all[i] = all[i - 1] + (a[i] > 0);
    }
    if (len == 1) {
        cout << 0;
        return 0;
    }
    sum_pref[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int color = 1; color <= k; color++) {
            if (a[i] != -1 && a[i] != color) continue;
            dp[i][color] = sum_pref[i - 1];
            if (i >= len && can(i - len + 1, i, color)) {
                dp[i][color] = sub(dp[i][color], sub(sum_pref[i - len], dp[i - len][color]));
            }
            sum_pref[i] = sum(sum_pref[i], dp[i][color]);
        }
    }
    cout << sum_pref[n];
    return 0;
}