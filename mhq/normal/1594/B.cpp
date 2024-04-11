#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
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
    const ll mod = (ll)1e9 + 7;
    while (tst--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        ll pw = 1;
        while (k > 0) {
            ans += (pw * (k % 2));
            ans %= mod;
            pw = (pw * n) % mod;
            k /= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}