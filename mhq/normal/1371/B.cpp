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
        ll n, r;
        cin >> n >> r;
        ll at_most = min(n - 1, r);
        ll f = (at_most * (at_most + 1)) / 2;
        if (r >= n) f++;
        cout << f << '\n';
    }
    return 0;
}
//a, b