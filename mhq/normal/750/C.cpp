#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const ll INF = (ll)1e18;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll upd = 0;
    ll l = -INF;
    ll r = INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, d;
        cin >> c >> d;
        if (d == 1) {
            l = max(l, 1900 - upd);
        }
        else {
            r = min(r, 1899 - upd);
        }
        upd += c;
    }
    if (l > r) {
        cout << "Impossible";
    }
    else if (r == INF) {
        cout << "Infinity";
    }
    else {
        cout << r + upd;
    }
    return 0;
}