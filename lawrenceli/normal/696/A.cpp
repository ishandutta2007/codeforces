#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q;
map<ll, ll> mp;

int sze(ll x) {
    int ret = 0;
    while (x > 0) ret++, x /= 2;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            ll a, b, w;
            cin >> a >> b >> w;
            if (a > b) swap(a, b);
            int x = sze(a), y = sze(b);
            for (int j = 0; j < y - x; j++) {
                mp[b] += w;
                b /= 2;
            }
            while (a != b) {
                mp[a] += w;
                mp[b] += w;
                a /= 2, b /= 2;
            }
        } else {
            ll a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            ll ans = 0;
            int x = sze(a), y = sze(b);
            for (int j = 0; j < y - x; j++) {
                ans += mp[b];
                b /= 2;
            }
            while (a != b) {
                ans += mp[a];
                ans += mp[b];
                a /= 2, b /= 2;
            }
            cout << ans << '\n';
        }
    }
}