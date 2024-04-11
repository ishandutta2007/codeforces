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
const int maxN = 4005;
int c[maxN][maxN];
int n, k, l;
int f[maxN];
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int fact[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> k >> l;
    l %= mod;
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = mult(f[i - 1], 2 * i - 1);
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = mult(fact[i - 1], i);
    int coef = mult(l, pw(2 * n + 1, mod - 2));
    int ans = 0;
    c[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    for (int i = 1; i < 2 * n; i++) {
        int a = i;
        int b = 2 * n - i;
        int total = f[n];
        int val = 0;
        for (int take = k; take <= min(a, b); take++) {
            if (take % 2 != a % 2) continue;
            int c1 = mult(fact[take], mult(c[a][take], c[b][take]));
            c1 = mult(c1, mult(f[(a - take) / 2], f[(b - take) / 2]));
            val = sum(val, c1);
        }
        ans = sum(ans, mult(val, pw(total, mod - 2)));
    }
    cout << mult(ans, coef);
    return 0;
}