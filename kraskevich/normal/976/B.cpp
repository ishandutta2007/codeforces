#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);
    
    ll n, m, k;
    cin >> n >> m >> k;
    ++k;
    if (k <= n) {
        cout << k << " " << 1 << endl;
        return 0;
    }
    k -= n + 1;
    ll len = 2 * m - 2;
    ll strip = k / len;
    ll pos = k % len;
    ll y = n - 2 * strip;
    ll x = 2 + pos;
    if (pos >= m - 1) {
        --y;
        x = 2 * m - pos - 1;
    }
    cout << y << " " << x << endl;
}