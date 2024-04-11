#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, x;
int a[nax];

void solve() {
    cin >> n >> x;
    int l = nax, r = 0;
    int64_t ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
        if (i > 1) ans += abs(a[i] - a[i - 1]);
    }
    if (n == 1) {
   //     cout << max(a[1], x) - 1 << '\n';
   //     return;
    }
    int y = a[1], z = a[n];
    if (y > z) swap(y, z);
    if (x < l) {
        ans += min(y - 1, (l - 1) * 2);
        cout << ans << '\n';
        return;
    }


    if (l > 1) {
        int ul = 1, ur = min(x, l - 1);
        ans += min(2 * (ur - ul + 1), y - 1);
    }
    if (r < x) {
        int ul = r + 1, ur = x;
        ans += min(2 * (ur - ul + 1), x - z);
    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}