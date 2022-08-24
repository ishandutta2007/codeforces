#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
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
        ll r, g, b;
        cin >> r >> g >> b;
        if (2 * max({r, g, b}) <= r + g + b + 1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}