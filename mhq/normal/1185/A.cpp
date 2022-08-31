#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll a[3];
    ll d;
    for (int i = 0; i < 3; i++) cin >> a[i];
    cin >> d;
    sort(a, a + 3);
    ll ans = 0;
    ans += max(0LL, d - (a[1] - a[0]));
    ans += max(0LL, d - (a[2] - a[1]));
    cout << ans;
    return 0;
}