#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1005], b[1005];
int c[2005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int k = 0;
    for (int i = 1; i < n; ++i) c[++k] = a[i], c[++k] = b[i+1];
    c[++k] = a[n];
    c[++k] = b[1];
    for (int i = 1; i <= k; ++i) if (c[i] == 1) return cout << -1 << endl, 0;
    double ans = m;
    for (int i = k; i >= 1; --i) ans = ans / (c[i] - 1) * c[i];
    cout << setprecision(15) << fixed << ans - m << endl;
    return 0;
}