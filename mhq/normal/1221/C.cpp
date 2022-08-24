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
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        ll c, m, x;
        cin >> c >> m >> x;
        cout << min({c, m, (c + m + x) / 3}) << '\n';
    }
    return 0;
}