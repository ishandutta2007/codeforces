#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
ll k;
const int maxN = 3 * (int)1e5 + 100;
ll a[maxN];
ll pref[maxN];
ll mx[11][maxN];
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 0; i < m; i++) {
        mx[i][n + 1] = -INF;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < m; j++) {
            mx[j][i] = mx[j][i + 1];
        }
        mx[i % m][i] = max(mx[i % m][i], m * pref[i] - k * i);
    }
    ll best = 0;
    for (int l = 0; l < n; l++) {
        ll our_val = m * pref[l] - k * l;
        for (int res = 0; res < m; res++) {
            ll max_pref = mx[(l + res) % m][l + 1];
            ll add = (m - res) % m;
            best = max(best, (max_pref - our_val - k * add) / m);
        }
    }
    cout << best;
    return 0;
}