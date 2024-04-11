#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, t, a[N][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        for (int fi = 0; fi < 5; fi++) {
            for (int se = fi + 1; se < 5; se++) {
                bool ok = true;
                int cfi = 0, cse = 0;
                for (int i = 1; i <= n; i++) {
                    if (a[i][fi] == 0 && a[i][se] == 0) {
                        ok = false;
                        break;
                    } else {
                        cfi += a[i][fi];
                        cse += a[i][se];
                    }
                }
                ok &= (cfi >= n / 2 && cse >= n / 2);
                if (ok) {
                    cout << "YES\n";
                    goto hell;
                }
            }
        }
        cout << "NO\n";
        hell: continue;
    }
}