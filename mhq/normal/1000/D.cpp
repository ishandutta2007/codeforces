#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1005;
int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int c[maxN][maxN];
int f[maxN], a[maxN], n;
bool ok[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int ans = 0;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] <= 0 || (i + a[i] > n)) continue;
        ok[i] = true;
        for (int j = i + a[i]; j <= n; j++) {
            f[i] = sum(f[i], mult(c[j - i - 1][a[i]], f[j]));
        }
        f[i] = sum(f[i], c[n - i][a[i]]);
        ans = sum(ans, f[i]);
    }
    cout << ans;
    return 0;
}