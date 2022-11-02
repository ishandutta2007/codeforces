#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (ll i = x; i <= y; i++) {
        ll a = i * k;
        if (l <= a && a <= r) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}