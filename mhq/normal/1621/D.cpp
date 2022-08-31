#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 505;
int n;
ll c[maxN][maxN];
ll getRect(int x1, int y1, int x2, int y2) {
    ll f = 0;
    for (int z = x1; z <= x2; z++) {
        for (int r = y1; r <= y2; r++) {
            f += c[z][r];
        }
    }
    return f;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                cin >> c[i][j];
                if (i > n && j > n) ans += c[i][j];
            }
        }
        ll best = 1e18;
        /*best = min(best, getRect(n + 1, 1, n + 1, n));
        best = min(best, getRect(1, n + 1, n, n + 1));

        best = min(best, getRect(2 * n, 1, 2 * n, n));
        best = min(best, getRect(1, 2 * n, n, 2 * n));

        best = min(best, getRect(n, n + 1, n, 2 * n));
        best = min(best, getRect(n + 1, n, 2 * n, n));

        best = min(best, getRect(1, n + 1, 1, 2 * n));
        best = min(best, getRect(n + 1, 1, 2 * n, 1));*/
        best = min({best, c[n][n + 1], c[n + 1][n], c[n + 1][1], c[1][n + 1], c[2 * n][1], c[1][2 * n], c[2 * n][n], c[n][2 * n]});
        ans += best;
        cout << ans << '\n';
    }
    return 0;
}