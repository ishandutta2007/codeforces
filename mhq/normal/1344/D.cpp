#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxN = 1e5 + 10;
int n;
ll k;
ll a[maxN];
const ll INF = 4e18;
ll cnt[maxN];
ll solve(ll val, ll lim) {
    //val -  3 * x^2 - 3x - 1 >= lim
    ll lower = val - lim - 1;
    if (lower < 0) return 0;
    if (3 * (val - 1) * (val - 1) + 3 * (val - 1) <= lower) return val;
    ll l = 0;
    ll r = val - 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (3 * mid * mid + 3 * mid <= lower) l = mid;
        else r = mid;
    }
    return l + 1;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll l = -INF;
    ll r = (ll)1e12;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += solve(a[i], mid);
        }
        if (cur >= k) l = mid;
        else r = mid;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] = solve(a[i], l + 1);
        k -= cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        while (k > 0 && cnt[i] + 1 <= a[i] && a[i] - 3 * cnt[i] * (cnt[i] + 1) - 1 == l) {
            cnt[i]++;
            k--;
        }
    }
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    assert(k == 0);

    return 0;
}