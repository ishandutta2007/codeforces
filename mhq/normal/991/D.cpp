#include <bits/stdc++.h>
using namespace std;
int dp[105][4];
const int INF = (int)1e9;
int st[105];
void upd(int& a, int b) {
    a = max(a, b);
}
bool can(int mask1, int mask2, int x, int y) {
    if ((mask1 & x) != 0) return false;
    if ((mask2 & y) != 0) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == 'X') st[i + 1]++;
        if (s2[i] == 'X') st[i + 1] += 2;
    }
    for (int i = 0; i < s1.size() + 1; i++) {
        for (int mask = 0; mask < 4; mask++) {
            dp[i][mask] = -INF;
        }
    }
    int n = s1.size();
    st[n + 1] = 3;
    dp[1][st[1]] = 0;
    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < 4; mask++) {
            upd(dp[i + 1][st[i + 1]], dp[i][mask]);
            if (can(mask, st[i + 1], 3, 1)) {
                upd(dp[i + 1][st[i + 1] ^ 1], dp[i][mask] + 1);
            }
            if (can(mask, st[i + 1], 3, 2)) {
                upd(dp[i + 1][st[i + 1] ^ 2], dp[i][mask] + 1);
            }
            if (can(mask, st[i + 1], 1, 3)) {
                upd(dp[i + 1][st[i + 1] ^ 3], dp[i][mask] + 1);
            }
            if (can(mask, st[i + 1], 2, 3)) {
                upd(dp[i + 1][st[i + 1] ^ 3], dp[i][mask] + 1);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < 4; i++) {
        upd(mx, dp[n + 1][i]);
    }
    cout << mx;
    return 0;
}