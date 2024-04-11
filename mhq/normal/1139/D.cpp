#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
int n, k;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
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
int mob[maxN];
int lp[maxN];
int getInv(int a) {
    return pw(a, mod - 2);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
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
    int ans = 0;
    int m;
    cin >> m;
    for (int i = 2; i <= m; i++) {
        int t = mult((m / i), getInv(m));
        int coef = mult(t, getInv(sub(1, t)));
        ans = sum(ans, mult(sub(0, mob[i]), coef));
    }
    cout << sum(ans, 1);
    return 0;
}