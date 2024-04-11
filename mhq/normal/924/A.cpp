#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[55][55];
vector < int > r[55];
vector < int > c[55];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                r[i].push_back(j);
                c[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) sort(r[i].begin(), r[i].end());
    for (int i = 1; i <= m; i++) sort(c[i].begin(), c[i].end());
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1 + 1; i2 <= n; i2++) {
            bool ok = false;
            for (int k = 1; k <= m; k++) {
                if (a[i1][k] == '#' && a[i2][k] == '#') {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                if (r[i1] != r[i2]) {
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    for (int i1 = 1; i1 <= m; i1++) {
        for (int i2 = i1 + 1; i2 <= m; i2++) {
            bool ok = false;
            for (int k = 1; k <= n; k++) {
                if (a[k][i1] == '#' && a[k][i2] == '#') {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                if (c[i1] != c[i2]) {
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}