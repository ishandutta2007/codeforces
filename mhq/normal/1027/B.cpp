#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, q;
void solve(int x, int y) {
    // 2 * k - 1 < x
    ll ans = 0;
    if ((x + y) % 2 == 0) {
        ll big = x / 2;
        ll small = (x - 1) / 2;
        ans += (big) * ((n + 1) / 2) + small * (n / 2);
        // y - 2 .. 1
        ans += (y - 1) / 2;
        ans++;
    }
    else {
        ans += (1LL * n * n + 1) / 2;
        ll big = (x - 1) / 2;
        ll small = (x / 2);
        ans += (big) * ((n + 1) / 2) + small * (n / 2);
        ans += (y - 1) / 2;
        ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}