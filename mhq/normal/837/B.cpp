#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
char a[105][105];
char b[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int iter = 0; iter < 2; iter++) {
        if (n % 3 == 0) {
            map < char, int > was;
            bool ok = true;
            for (int j = 0; j < 3; j++) {
                int fr = (1 + (n / 3) * j);
                int lst = (n / 3) * (j + 1);
                for (int k = fr; k <= lst; k++) {
                    for (int p = 1; p <= m; p++) {
                        if (a[k][p] != a[fr][1]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (was.count(a[fr][1])) {
                    ok = false;
                    break;
                }
                was[a[fr][1]] = true;
            }
            if (ok) {
                cout << "YES";
                return 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[j][i] = a[i][j];
            }
        }
        swap(n, m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = b[i][j];
            }
        }
    }
    cout << "NO";
    return 0;
}