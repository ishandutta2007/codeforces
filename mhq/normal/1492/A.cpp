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
        ll a[3];
        ll p;
        cin >> p;
        ll best = 5e18;
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            best = min(best, a[i] * ((p + a[i] - 1) / a[i]));
        }
        cout << best - p << '\n';
    }
    return 0;
}