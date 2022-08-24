#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int dp[maxN][2];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
       ll x, y, k;
       cin >> x >> y >> k;
       ll need = (y * k + k);
       cout << (need - 1 + x - 2) / (x - 1) + k << '\n';
    }
    return 0;
}