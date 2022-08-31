#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll calc(ll x, ll plus, ll minus) {
    if (x >= 0) return plus * x;
    else return minus * (-x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll x, y;
        cin >> x >> y;
        ll c1, c2, c3, c4, c5, c6;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        ll best = 5e18;
        best = min(best, calc(x, c6, c3) + calc(y, c2, c5));
        best = min(best, calc(y, c1, c4) + calc(x - y, c6, c3));
        best = min(best, calc(x, c1, c4) + calc(y - x, c2, c5));
        cout << best << '\n';
    }
    return 0;
}