#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll m;
ll mult(ll a, ll b) {
    return (1LL * a * b) % m;
}
ll sum(ll a, ll b) {
    int s = a + b;
    s %= m;
    return s;
}
ll d;
void solve() {
    cin >> d >> m;
    ll ans = 1 % m;
    for (int i = 0; i <= 40; i++) {
        if ((1LL << i) > d) break;
        ll sz = min(d, (1LL << (i + 1)) - 1) - (1LL << i) + 1;
        ans = mult(ans, sum(sz, 1));
    }
    ans -= 1;
    ans %= m;
    if (ans < 0) ans += m;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}