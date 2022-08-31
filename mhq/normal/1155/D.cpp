#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 3 * (int)1e5 + 100;
ll pref[maxN];
int n, x;
ll a[maxN];
ll bestP[maxN], bestS[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> x;
    ll mn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        mn = min(mn, pref[i]);
        bestP[i] = pref[i] - mn;
    }
    ll mx = pref[n];
    for (int i = n; i >= 1; i--) {
        mx = max(mx, pref[i - 1]);
        bestS[i] = mx - pref[i - 1];
    }
    ll opt = bestS[n + 1] + pref[n] * x;
    ll ans = 0;
    for (int i = n; i >= 0; i--) {
        ans = max(ans, opt - pref[i] * x + bestP[i]);
        if (i > 0) opt = max(opt, bestS[i] + pref[i - 1] * x);
    }
    cout << ans;
    return 0;
}