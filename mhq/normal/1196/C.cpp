#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 3 * (int)1e5 + 100;
const int INF = 100 * 1000;
void solve() {
    int xmin = -INF, xmax = INF, ymin = -INF, ymax = INF;
    cin >> n;
    while (n--) {
        int curx, cury;
        cin >> curx >> cury;
        for (int j = 1; j <= 4; j++) {
            int c;
            cin >> c;
            if (c == 0) {
                if (j == 1) {
                    xmin = max(xmin, curx);
                }
                else if (j == 2) {
                    ymax = min(ymax, cury);
                }
                else if (j == 3) {
                    xmax = min(xmax, curx);
                }
                else if (j == 4) {
                    ymin = max(ymin, cury);
                }
            }
        }
    }
    if (xmin > xmax || ymin > ymax) cout << "0" << '\n';
    else cout << 1 << " " << xmin << " " << ymin << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}