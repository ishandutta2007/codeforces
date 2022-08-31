#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        if (2 * k - 1 <= n) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j && i % 2 == 1 && (i - 1) / 2 < k) cout << "R";
                    else cout << ".";
                }
                cout << '\n';
            }
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}