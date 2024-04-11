#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[2005][2005];
void check(int x1, int x2, int y1, int y2) {
    if (x2 - x1 != y2 - y1) return;
    if (min(x1, x2) < 1 || max(x1, x2) > n) return ;
    if (min(y1, y2) < 1 || max(y1, y2) > m) return ;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'w') {
                if ((i == x1) || (i == x2) || (j == y1) || (j == y2)) {
                    if ((x1 <= i && i <= x2) && (y1 <= j && j <= y2)) {
                    }
                    else ok = false;
                }
                else ok = false;
            }
        }
    }
    if (!ok) return ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i == x1) || (i == x2) || (j == y1) || (j == y2)) {
                if ((x1 <= i && i <= x2) && (y1 <= j && j <= y2)) {
                    if (a[i][j] == 'w') cout << 'w';
                    else cout << '+';
                }
                else cout << a[i][j];
            }
            else cout << a[i][j];
        }
        cout << '\n';
    }
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int maxr = -1;
    int minr = 2005;
    int maxc = -1;
    int minc = 2005;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'w') {
                maxr = max(maxr, i);
                minr = min(minr, i);
                maxc = max(maxc, j);
                minc = min(minc, j);
            }
        }
    }
    /*if (minr == maxr) {
        check(minr, minr + maxc - minc, minc, maxc);
        check(minr - (maxc - minc), minr, minc, maxc);
        cout << "-1";
    }
    if (minc == maxc) {
        check(minr, maxr, minc, minc + (maxr - minr));
        check(minr, maxr, minc - (maxr - minr), minc);
        cout << "-1";
    }*/
    if (maxr - minr < maxc - minc) {
        check(minr, maxr, minc, minc + (maxr - minr));
        check(minr, maxr, maxc - (maxr - minr) , maxc);
        check(1, 1 + (maxc - minc), minc, maxc);
        check(n - (maxc - minc), n, minc, maxc);
        check(minr, minr + (maxc - minc), minc, maxc);
        check(maxr - (maxc - minc), maxr, minc, maxc);
    }
    else {
        check(minr, minr + (maxc - minc), minc, maxc);
        check(maxr - (maxc - minc), maxr, minc, maxc);
        check(1, 1 + (maxc - minc), minc, maxc);
        check(n - (maxc - minc), n, minc, maxc);
        check(minr, maxr, 1, 1 + (maxr - minr));
        check(minr, maxr, m - (maxr - minr), m);
        check(minr, maxr, minc, minc + (maxr - minr));
        check(minr, maxr, maxc - (maxr - minr) , maxc);
    }
    cout << "-1";
    return 0;
}