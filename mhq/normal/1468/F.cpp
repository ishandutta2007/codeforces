#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    map<pair<int,int>,int> mp;
    for (int i = 1; i <= n; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u -= x;
        v -= y;
        int d = __gcd(abs(u), abs(v));
        u /= d; v /= d;
        ans += mp[make_pair(-u, -v)];
        mp[make_pair(u, v)]++;
    }
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