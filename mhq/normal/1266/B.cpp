#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bitset < 500 > dp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int i = 1; i <= 6; i++) {
        dp[21 - i] = true;
    }
    for (int i = 1; i <= 100; i++) {
        dp |= dp << 14;
    }
    int tst;
    cin >> tst;
    while (tst--) {
        ll x;
        cin >> x;
        if (x > 200) {
            x = (x % 14) + 56;
        }
        cout << (dp[x] ? "YES" : "NO") << '\n';
    }
    return 0;
}