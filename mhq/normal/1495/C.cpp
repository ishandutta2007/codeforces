#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 505;
char a[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        int start;
        if (n % 3 == 0) start = 2;
        else start = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j == 1 || (i % 3 == start)) a[i][j] = 'X';
            }
        }
        if (m > 1) {
            if (start == 1) {
                for (int i = 2; i <= n; i += 3) {
                    if (a[i][2] == 'X' || ((i + 1) <= n && a[i + 1][2] == 'X')) {
                        a[i][2] = 'X';
                        a[i][1] = '.';
                        if ((i + 1) <= n) {
                            a[i + 1][2] = 'X';
                            a[i + 1][1] = '.';
                        }
                    }
                }
            }
            else {
                for (int i = 0; i <= n; i += 3) {
                    if ((i > 0 && a[i][2] == 'X') || ((i + 1) <= n && a[i + 1][2] == 'X')) {
                        if (i > 0) {
                            a[i][2] = 'X';
                            a[i][1] = '.';
                        }
                        if ((i + 1) <= n) {
                            a[i + 1][2] = 'X';
                            a[i + 1][1] = '.';
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}