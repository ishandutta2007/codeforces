#include <bits/stdc++.h>
using namespace std;
int n, k;
int mod = (int)1e9 + 7;
int coef[5005];
int f[5005][5005];
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int inv2 = (mod + 1) / 2;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    int p = pw(a, b / 2);
    if (b & 1) return mult(a, mult(p, p));
    else return mult(p, p);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    coef[1] = mult(n, pw(2, n - 1));
    for (int i = 2; i <= k; i++) {
        coef[i] = mult(coef[i - 1], mult(n - i + 1, inv2));
    }
    f[1][1] = 1;
    for (int i = 2; i <= k; i++) {
        for (int j = i; j >= 1; j--) {
            f[i][j] = f[i - 1][j - 1];
        }
        for (int j = i; j >= 1; j--) {
            f[i][j] = sum(f[i][j], mult(f[i - 1][j], j));
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans = sum(ans, mult(coef[i], f[k][i]));
    }
    cout << ans;
    return 0;
}