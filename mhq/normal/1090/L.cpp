#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t, n, a, b, k;
ll can(ll val) {
    ll days1 = (n + 1) / 2;
    ll days2 = n / 2;
    if (days1 * min(a, val) + days2 * min(b, val) >= val * k) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> t >> n >> a >> b >> k;
    if (k > n) {
        cout << 0;
        return 0;
    }
    ll l = 0;
    ll r = t;
    if (can(r)) {
        cout << r;
        return 0;
    }
    else {
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (can(mid)) l = mid;
            else r = mid;
        }
        cout << l;
    }
    return 0;
}