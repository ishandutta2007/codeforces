#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
char c[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        y = min(y, 2 * x);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
                if (c[i][j] == '.') {
                    if (j != 1 && c[i][j - 1] == '.' && c[i][j] == '.') {
                        c[i][j] = '*';
                        c[i][j - 1] = '*';
                        ans += y;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == '.') ans += x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}