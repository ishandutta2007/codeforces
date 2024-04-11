#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
const int maxK = 205;
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
int dp[205][3];
int pref[maxK][3];
int ndp[205][3];
int n;
int a[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[1] == -1) {
        for (int i = 1; i <= 200; i++) {
            dp[i][1] = 1;
            pref[i][1] = i;
        }
    }
    else {
        dp[a[1]][1] = 1;
        for (int i = a[1]; i <= 200; i++) {
            pref[i][1] = 1;
        }
    }
    // 0 - equal
    // 1 - ai > a(i - 1)
    // 2 - ai < a(i - 1)
    for (int i = 1; i + 1 <= n; i++) {
        memset(ndp, 0, sizeof ndp);
        if (a[i + 1] != -1) {
            ndp[a[i + 1]][0] = sum(ndp[a[i + 1]][0], sum(sum(dp[a[i + 1]][0], dp[a[i + 1]][1]), dp[a[i + 1]][2]));
            ndp[a[i + 1]][1] = sum(ndp[a[i + 1]][1], sum(sum(pref[a[i + 1] - 1][0], pref[a[i + 1] - 1][1]), pref[a[i + 1] - 1][2]));
            ndp[a[i + 1]][2] = sum(ndp[a[i + 1]][2], sub(pref[200][0], pref[a[i + 1]][0]));
            ndp[a[i + 1]][2] = sum(ndp[a[i + 1]][2], sub(pref[200][2], pref[a[i + 1]][2]));
        }
        else {
            for (int x = 1; x <= 200; x++) {
                a[i + 1] = x;
                ndp[a[i + 1]][0] = sum(ndp[a[i + 1]][0], sum(sum(dp[a[i + 1]][0], dp[a[i + 1]][1]), dp[a[i + 1]][2]));
                ndp[a[i + 1]][1] = sum(ndp[a[i + 1]][1], sum(sum(pref[a[i + 1] - 1][0], pref[a[i + 1] - 1][1]), pref[a[i + 1] - 1][2]));
                ndp[a[i + 1]][2] = sum(ndp[a[i + 1]][2], sub(pref[200][0], pref[a[i + 1]][0]));
                ndp[a[i + 1]][2] = sum(ndp[a[i + 1]][2], sub(pref[200][2], pref[a[i + 1]][2]));
            }
        }
        for (int i = 1; i <= 200; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = ndp[i][j];
                pref[i][j] = sum(pref[i - 1][j], dp[i][j]);
            }
        }
    }
    cout << sum(pref[200][2], pref[200][0]);
    return 0;
}