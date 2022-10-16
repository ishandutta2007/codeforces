#include <bits/stdc++.h>

using namespace std;

int n;
int a[707];
int f[707][707];
int g[707][707];
int d[707][707];

int G(int, int);

int F(int l, int r) {
    if (f[l][r] != -1) return f[l][r];
    if (l > r) return f[l][r] = 1;
    if (l == r) return f[l][r] = d[l][l+1] > 1;
    for (int k = l; k <= r; ++k) if (d[k][r+1] > 1 && F(l, k - 1) && G(k + 1, r)) return f[l][r] = 1;
    return f[l][r] = 0;
}
int G(int l, int r) {
    if (g[l][r] != -1) return g[l][r];
    if (l > r) return g[l][r] = 1;
    if (l == r) return g[l][r] = d[l-1][l] > 1;
    for (int k = l; k <= r; ++k) if (d[l-1][k] > 1 && F(l, k - 1) && G(k + 1, r)) return g[l][r] = 1;
    return g[l][r] = 0;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= n + 1; ++j) if (a[i] || a[j]) d[i][j] = __gcd(a[i], a[j]);
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= n + 1; ++j) f[i][j] = g[i][j] = -1;
    cout << (F(1, n) ? "Yes" : "No") << endl;
    return 0;
}