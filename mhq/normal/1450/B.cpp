#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int x[maxN], y[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            bool f = true;
            for (int j = 1; j <= n; j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) {
                    f = false;
                    break;
                }
            }
            if (f) ok = true;
        }
        if (ok) cout << 1 << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}