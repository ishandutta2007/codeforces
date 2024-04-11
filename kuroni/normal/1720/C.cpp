#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int m, n; cin >> m >> n;
        int ans = 0;
        vector a(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = (s[j] == '1');
                ans += a[i][j];
            }
        }
        for (int mi = 1; mi < 4; mi++) {
            bool ok = false;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    int tot = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
                    for (int k = 0; k < 2; k++) {
                        for (int l = 0; l < 2; l++) {
                            tot -= a[i + k][j + l];
                            if (tot == mi) {
                                ok = true;
                                goto nice;
                            }
                            tot += a[i + k][j + l];
                        }
                    }
                }
            }
            nice:
                if (ok) {
                    ans -= mi - 1;
                    break;
                }
        }
        cout << ans << '\n';
    }
}