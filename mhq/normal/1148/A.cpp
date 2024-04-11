#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 2 * c + 2 * min(a, b);
    if (a != b) ans++;
    cout << ans;
    return 0;
}