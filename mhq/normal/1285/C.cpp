#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll x;
    cin >> x;
    ll mx = 1e18;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (__gcd(i, x / i) == 1) mx = min(mx, x / i);
        }
    }
    cout << mx << " " << x / mx;
    return 0;
}