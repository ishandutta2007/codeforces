#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e7 + 10;
int n;
ll l, r;
unsigned long long x, y, z;
unsigned long long b[maxN];
ll a[maxN];
const ll INF = 4 * (ll)1e18 + 100;
ll ans = INF;
ll mn[maxN];
ll mx[maxN];
void solve() {
    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
    unsigned long long mod = (1LL << 32);
    for (int i = 3; i <= n; i++) {
        b[i] = (x * b[i - 2] + y * b[i - 1] + z) % mod;
    }
    ans = INF;
    mn[0] = INF;
    mx[n + 1] = -INF;
    for (int i = 1; i <= n; i++) {
        ll t = b[i];
        a[i] = ((t % (r - l + 1)) + l);
        //cout << a[i] << endl;
        if (a[i] > mn[i - 1]) {
            ans = min(ans, a[i] * mn[i - 1]);
        }
        mn[i] = min(mn[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] < mx[i + 1]) {
            ans = min(ans, a[i] * mx[i + 1]);
        }
        mx[i] = max(mx[i + 1], a[i]);
    }
    if (ans == INF) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}