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
    return (int)((1LL * a * b) % mod);
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 2 * (int)1e5 + 10;
int n, m, sz;
int b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> sz;
    for (int i = 1; i <= m; i++) cin >> b[i];
    int ans = pw(sz, (n - 2 * b[m]) % mod);
    for (int i = 1; i <= m; i++) {
        int all = pw(sz, (b[i] - b[i - 1]));
        ans = mult(ans, (int)(((1LL * all * (all + 1)) / 2) % mod));
    }
    cout << ans;
    return 0;
}