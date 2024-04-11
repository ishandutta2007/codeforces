#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[105][105], v[105][105];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j], v[i][j] = 0;
        for (int s = 1; s <= m; ++s) {
            int ix = -1, iy = -1;
            for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (!v[i][j] && (ix == -1 || a[i][j] < a[ix][iy])) ix = i, iy = j;
            swap(a[ix][s], a[ix][iy]);
            v[ix][s] = 1;
        }
        for (int i = 1; i <= n; ++i) { for (int j = 1; j <= m; ++j) cout << a[i][j] << ' '; cout << endl; }
    }

    return 0;
}