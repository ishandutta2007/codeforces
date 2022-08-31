#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    int k;
    cin >> k;
    int sz = sqrt(k) + 2;
    while ((sz - 1) * (sz - 1) >= k) sz--;
    k -= (sz - 1) * (sz - 1);
    if (k <= sz) {
        cout << k << " " << sz << '\n';
    }
    else {
        cout << sz << " " << 2 * sz - k << '\n';
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