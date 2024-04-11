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
        ll l, r;
        cin >> l >> r;
        if (2 * l <= r) {
            cout << l << " " << 2 * l << '\n';
        }
        else {
            cout << -1 << " " << -1 << '\n';
        }
    }
    return 0;
}