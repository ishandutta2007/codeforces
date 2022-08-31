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
        int n;
        cin >> n;
        int mx = INT_MIN;
        int need = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mx = max(mx, x);
            need = max(need, mx - x);
        }
        if (need == 0) {
            cout << 0 << '\n';
            continue;
        }
        for (int p = 0; ; p++) {
            if ((1LL << p) - 1 >= need) {
                cout << p << '\n';
                break;
            }
        }
    }
    return 0;
}