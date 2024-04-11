#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int dif = abs(b - a);
    if (max({a, b, c}) > 2 * dif) {
        cout << -1 << '\n';
    }
    else {
        cout << (c > dif ? c - dif : c + dif) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}