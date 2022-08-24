#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int dp[1005][1005];
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(mult(a, a), b / 2));
    else return pw(mult(a, a), b / 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int pa, pb, k;
    cin >> k >> pa >> pb;
    int revb = pw(pb, mod - 2);
    int revs = pw(pa + pb, mod - 2);
    for (int y = 0; y <= k + 1; y++) {
        dp[k + 1][y] = sum(k + 1, mult(pa, revb));
    }
    for (int x = k; x >= 0; x--) {
        for (int y = 1; y <= k; y++) {
            if (x >= y) {
                dp[x][y] = sum(x, mult(pa, revb));
            }
            else if (x != 0){
                dp[x][y] = mult(revs, sum(mult(pa, dp[x + 1][y]), mult(pb, sum(dp[x][y - x], x))));
                //dp[x][y] = ((pa) / (pa + pb)) * dp[x + 1][y] + (pb / (pa + pb)) * (dp[x][y - x] + x);
            }
            else {
                dp[x][y] = dp[x + 1][y];
            }
        }
    }
    cout << dp[0][k];
    return 0;
}