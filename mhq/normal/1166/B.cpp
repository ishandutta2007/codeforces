#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
char f[] = {'a', 'e', 'i', 'o', 'u'};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0) {
            if (i >= 5 && (k / i) >= 5) {
                int n = i;
                int m = k /i;
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < m; jj++) {
                        cout << f[(ii + jj) % 5];
                    }
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}