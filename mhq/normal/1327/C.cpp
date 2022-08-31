#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = 205;
int a[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    vector < char > all;
    cout << (n - 1) + (m - 1) + (n * m - 1) << '\n';
    for (int i = 1; i <= n - 1; i++) {
        cout << "U";
    }
    for (int j = 1; j <= m - 1; j++) {
        cout << "L";
    }
    int a = 1;
    int b = 1;
    for (int row = 1; row <= n; row++) {
        if (row % 2 == 1) {
            for (int col = 1; col <= m - 1; col++) {
                cout << "R";
            }
        }
        else {
            for (int col = m; col >= 2; col--) {
                cout << "L";
            }
        }
        if (row != n) {
            cout << "D";
        }
    }
    return 0;
}