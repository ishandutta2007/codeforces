#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll s1 = x1 + y1;
        ll s2 = x2 + y2;
        ll mn = 0;
        ll mx = (y2 - y1) * (x2 - x1);
        cout << mx + 1 << '\n';
    }
    return 0;
}