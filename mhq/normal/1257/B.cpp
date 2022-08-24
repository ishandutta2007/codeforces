#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int x, y;
        cin >> x >> y;
        if (x >= 4) x = 1e9 + 100;
        else if (x == 2) x = 3;
        if (x >= y) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

    }
    return 0;
}