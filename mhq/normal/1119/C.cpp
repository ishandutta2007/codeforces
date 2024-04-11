#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 505;
int a[2][maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[k][i][j];
            }
        }
    }
    for (int i = n; i > 1; i--) {
        for (int j = m; j > 1; j--) {
            if (a[1][i][j] != a[0][i][j]) {
                a[1][i][j] ^= 1;
                a[1][i][1] ^= 1;
                a[1][1][j] ^= 1;
                a[1][1][1] ^= 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[0][i][j] != a[1][i][j]) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}