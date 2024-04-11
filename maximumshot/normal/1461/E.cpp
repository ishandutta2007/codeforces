#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

bool slow(ll k, ll l, ll r, ll t, ll x, ll y) {
    for (ll i = 0; i < t; i++) {
        if (k + y <= r)
            k += y;
        k -= x;
        if (k < l)
            return false;
    }
    return true;
}

bool fast(ll k, ll l, ll r, ll t, ll x, ll y) {
    if (y < x) {
        if (k + y > r)
            k -= y;
        return t <= (k - l) / (x - y);
    }
    if (x + y <= r - l + 1)
        return true;
    if (k + y > r && k - x < l)
        return false;
    if (k + y > r)
        k -= y;
    while (t > 0) {
        k += y;
//        while (t > 0 && k >= l + x) {
//            k -= x;
//            t--;
//        }
        // k - z * x <= l + x - 1
        // z * x >= k - l - x + 1
        if (k >= l + x) {
            ll z = (k - l - x + 1 + x - 1) / x;
            z = min(z, t);
            t -= z;
            k -= z * x;
        }
        if (k > r - y && t > 0)
            return false;
    }
    return true;
}

void work() {
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    bool fs = fast(k, l, r, t, x, y);

    cout << (fs ? "Yes" : "No") << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}