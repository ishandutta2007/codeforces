#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
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
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 1) {
            int ans = 1;
            for (int i = 1; i <= n - 1; i++) ans = mult(ans, 2);
            ans = sum(ans, 1);
            int f = 1;
            for (int z = 0; z < k; z++) f = mult(f, ans);
            cout << f << '\n';
        }
        else {
            int ans = 1;
            for (int i = 1; i <= n - 1; i++) ans = mult(ans, 2);
            int X = pw(2, n);
            int nans = (ans + mod - 1) % mod;
            int tot = pw(nans, k);
            for (int bit = 0; bit < k; bit++) {
                tot = sum(tot, mult(pw(X, bit), pw(nans, k - 1 - bit)));
            }
            cout << tot << '\n';
        }
    }
}