#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok(ll n, ll k) {
    ll cop = n;
    ll cnt = 0;
    while (n > 0) {
        if (n <= k) {
            cnt += n;
            break;
        }
        cnt += k;
        n -= k;
        ll t = (n / 10);
        n -= t;
    }
    if (cnt * 2 >= cop) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    if (ok(n, 1)) {
        cout << 1;
        return 0;
    }
    ll l = 1;
    ll r = n;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (ok(n, mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}