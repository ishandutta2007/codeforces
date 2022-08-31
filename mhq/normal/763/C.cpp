#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, mod;
const int maxN = 1e5 + 10;
int a[maxN];
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
void check(int x, int d) {
    for (int j = 0; j <= n - 1; j++) {
        int who = sum(x, mult(j, d));
        int p = lower_bound(a, a + n, who) - a;
        if (p == n || a[p] != who) return;
    }
    cout << x << " " << d;
    exit(0);
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> mod >> n;
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s1 = sum(s1, a[i]);
        s2 = sum(s2, mult(a[i], a[i]));
    }
    sort(a, a + n);
    assert(mod >= n);
    if (mod == n) {
        cout << 0 << " " << 1;
        return 0;
    }
    if (n == 1) {
        cout << a[0] << " " << 0;
        return 0;
    }
    int val = (int)((1LL * n * (n - 1) / 2) % mod);
    val = pw(val, mod - 2);
    assert(val != 0);
    for (int x = 0; x < n; x++) {
        int his_val = mult(val, sub(s1, mult(a[x], n)));
        if (his_val == 0) continue;
        int R1 = (1LL * n * (n - 1) / 2) % mod;
        int R2 = ((1LL * n * (n - 1) * (2 * n - 1)) / 6) % mod;
        int gg = sum(mult(n, mult(a[x], a[x])), mult(2, mult(a[x], mult(R1, his_val))));
        gg = sum(gg, mult(his_val, mult(his_val, R2)));
        if (gg != s2) continue;
        check(a[x], his_val);
    }
    cout << -1;

    return 0;
}