#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll gen(ll l, ll r) {
    ll len = r - l + 1;
    ll x = (rand() ^ (rand() + 231)) % len;
    return x + l;
}
ll n, k;
bool ask(ll x, ll y) {
    cout << x << " " << y << endl;
    string ans;
    cin >> ans;
    if (ans == "Yes") {
        if (x == y) exit(0);
        return true;
    }
    else return false;
}
const ll BUBEN = 40;
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    ll l = 1;
    ll r = n;
    while (1) {
        while (r - l > BUBEN) {
            ll mid = (l + r) / 2;
            if (ask(l, mid)) {
                l = max(l - k, 1LL);
                r = min(mid + k, n);
            }
            else {
                l = max(mid + 1 - k, 1LL);
                r = min(r + k, n);
            }
        }
        ll t = gen(l, r);
        if (ask(t, t)) return 0;
        else {
            l = max(l - k, 1LL);
            r = min(r + k, n);
        }
    }
    return 0;
}