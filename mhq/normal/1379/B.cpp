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
       ll l, r, m;
       cin >> l >> r >> m;
       ll from = max(1LL, m - r + l);
       ll to = m + r - l;
       for (ll p = l; p <= r; p++) {
           ll at_least = ((from + p - 1) / p) * p;
           if (at_least <= to) {
               ll diff = m - at_least;
               if (diff >= 0) {
                   cout << p << " " << l + diff << " " << l << '\n';
               }
               else {
                   cout << p << " " << l << " " << l - diff << '\n';
               }
               break;
           }
       }
    }
    return 0;
}