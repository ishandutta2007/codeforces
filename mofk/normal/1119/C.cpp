#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[505][505], b[505][505];
int r[505], c[505];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> b[i][j], a[i][j] ^= b[i][j];
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        r[i] ^= a[i][j];
        c[j] ^= a[i][j];
    }
    for (int i = 1; i <= n; ++i) if (r[i]) return cout << "No" << endl, 0;
    for (int i = 1; i <= m; ++i) if (c[i]) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}