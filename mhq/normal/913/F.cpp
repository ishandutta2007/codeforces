#include <bits/stdc++.h>
using namespace std;
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
        if (b % 2 == 1) {
            return mult(a, pw(mult(a, a), b / 2));
        }
        else return pw(mult(a, a), b / 2);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int n, a, b, p;
int g[2005];
int s[2005][2005];
int power[2005];
int rpower[2005];
int ans[2005];
int q[10][10];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    p = mult(a, pw(b, mod - 2));
    for (int i = 0; i <= 2002; i++) {
        s[0][i] = 1;
        s[i][0] = 1;
    }
    power[0] = 1;
    rpower[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = mult(power[i - 1], p);
        rpower[i] = mult(rpower[i - 1], 1 + mod - p);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = sum(mult(s[i - 1][j], power[j]), mult(s[i][j - 1], rpower[i]));
        }
    }
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
        int cur = 1;
        for (int j = 1; j <= i - 1; j++) {
            cur = sub(cur, mult(g[j], s[j][i - j]));
        }
        g[i] = cur;
    }
    //cout << mult(g[4], 64) << '\n';
    //n = 4;
    for (int i = 2; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= (i - 1); j++) {
            int cnt = (j * (i - j) + (j * (j - 1)) / 2) % mod;
            cur = sum(cur, mult(s[j][i - j], mult(g[j], sum(cnt, sum(ans[i - j], ans[j])))));
            //if (i == n) cout << cur << '\n';
        }
        cur = sum(cur, mult(g[i], (i * (i - 1)) / 2));
        ans[i] = mult(cur, pw(mod + 1 - g[i], mod - 2));
    }
    cout << ans[n];
    return 0;
}