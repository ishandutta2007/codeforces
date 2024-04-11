#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1005;
int a[maxN][maxN];
int b[maxN][maxN];
int go() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (n % 4 == 2) {
                if (i > j && ((i % 4 == 2 && j % 4 == 1) || (i % 4 == 0 && j % 4 == 3))) ans ^= a[i][j];
            }
            else {
                if (i > j && ((i % 4 == 2 && j % 4 == 3) || (i % 4 == 0 && j % 4 == 1))) ans ^= a[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (n % 4 == 2) {
                if (i < j && ((i % 4 == 1 && j % 4 == 0) || (i % 4 == 3 && j % 4 == 2))) ans ^= a[i][j];
            }
            else {
                if (i < j && ((i % 4 == 1 && j % 4 == 2) || (i % 4 == 3 && j % 4 == 0))) ans ^= a[i][j];
            }
        }
    }
    return ans;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int f = 0;
    f ^= go();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[n + 1 - j][i] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = b[i][j];
        }
    }
    f ^= go();
    cout << f << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}