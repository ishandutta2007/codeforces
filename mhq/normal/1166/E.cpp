#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 55;
const int maxK = (int)1e4 + 100;
bool f[maxN][maxK];
int m, n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            int t;
            cin >> t;
            f[i][t] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            bool hs = false;
            for (int k = 1; k <= n; k++) {
                if (f[i][k] && f[j][k]) {
                    hs = true;
                    break;
                }
            }
            if (!hs) {
                cout << "impossible";
                return 0;
            }
        }
    }
    cout << "possible";
    return 0;
}