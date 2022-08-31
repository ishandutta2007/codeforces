#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
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
const int maxN = 2005;
int stir[maxN][maxN];
int inv[maxN];
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    stir[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        for (int j = 1; j <= i; j++) {
            stir[i][j] = sum(stir[i - 1][j - 1], mult(j, stir[i - 1][j]));
        }
    }
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m, k;
        cin >> n >> m >> k;
        int odd = (m + 1) / 2;
        int even = (m / 2);
        int ans = 0;
        int orig = pw(m, n);
        int cur_c = orig;
        int my_inv = pw(m, mod - 2);
        for (int p = 1; p <= k && p <= n; p++) {
            cur_c = mult(cur_c, n - p + 1);
            cur_c = mult(cur_c, odd);
            cur_c = mult(cur_c, my_inv);
            ans = sum(ans, mult(cur_c, stir[k][p]));
        }
        cout << ans << '\n';
    }
    return 0;
}