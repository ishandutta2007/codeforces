#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 2005;
int dp[maxN][maxN];
string s;
int tp[maxN];
int dp0[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> s;
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') tp[i + 1] = 1;
        else if (s[i] == ')') tp[i + 1] = 0;
        else tp[i + 1] = 2;
    }
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        if (tp[i] == 1) {
            for (int cnt = 1; cnt <= i; cnt++) {
                dp[i][cnt] = dp[i - 1][cnt - 1];
            }
        }
        else if (tp[i] == 0) {
            for (int cnt = 0; cnt <= i; cnt++) {
                dp[i][cnt] = dp[i - 1][cnt];
            }
        }
        else {
            for (int cnt = 0; cnt <= i; cnt++) {
                dp[i][cnt] = dp[i - 1][cnt];
                if (cnt) dp[i][cnt] = sum(dp[i][cnt], dp[i - 1][cnt - 1]);
            }
        }
    }
    dp0[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        if (tp[i] == 0 || tp[i] == 2) {
            for (int cnt = 1; cnt <= n - i + 2; cnt++) {
                dp0[i][cnt] = sum(dp0[i + 1][cnt - 1], dp0[i][cnt]);
             }
        }
        if (tp[i] == 1 || tp[i] == 2) {
            for (int cnt = 0; cnt <= n - i + 2; cnt++) {
                dp0[i][cnt] = sum(dp0[i + 1][cnt], dp0[i][cnt]);
            }
        }
    }
    int val = 0;
    for (int pref = 1; pref <= n; pref++) {
        int pref_sum = 0;
        for (int cnt = n; cnt >= 1; cnt--) {
            pref_sum = sum(pref_sum, dp0[pref + 1][cnt]);
            if (pref_sum == 0) continue;
            if (tp[pref] == 0) continue;
//            cout << pref << " " << cnt << " " << dp[pref - 1][cnt - 1] << " " << pref_sum << endl;
            val = sum(val, mult(pref_sum, dp[pref - 1][cnt - 1]));
        }
    }
    cout << val << '\n';
    return 0;
}