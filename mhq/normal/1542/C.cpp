#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    const int mod = (int)1e9 + 7;
    while (tst--) {
        ll n;
        cin >> n;
        ll ans = n % mod;
        ll z = 1;
        for (ll i = 1; ; i++) {
            z = lcm(z, i);
            if (z > n) break;
            ans += (n / z);
            ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}