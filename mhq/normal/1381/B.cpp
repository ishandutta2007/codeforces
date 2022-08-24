#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4005;
int p[maxN];
bool can[maxN][maxN];
int mx[maxN];
int where[maxN];
void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i];
        where[p[i]] = i;
        mx[i] = max(mx[i - 1], p[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            can[i][j] = false;
            if (i == 0 || j == 0) {
                can[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int len = i + j;
            int pos = where[mx[len]];
            int sz = len - pos + 1;
            if (i >= sz) {
                can[i][j] |= can[i - sz][j];
            }
            if (j >= sz) {
                can[i][j] |= can[i][j - sz];
            }
        }
    }
    cout << (can[n][n] ? "YES" : "NO") << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while(tst--) {
        solve();
    }
    return 0;
}