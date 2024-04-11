#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ll cnt = 0;
    for (ll i = 1; i <= 1e7; i++) {
        ll need = n + i;
        if ((n + i) % 3 != 0) continue;
        ll at_least = (i * (i + 1)) / 2;
        at_least *= 3;
        if (at_least <= need) cnt++;
    }
    cout << cnt;
    return 0;
}