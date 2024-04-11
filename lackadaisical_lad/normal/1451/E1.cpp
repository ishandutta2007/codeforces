#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    int x12, x13, x23, a12, a13, a23;
    cout << "XOR 1 2" << endl;
    cin >> x12;
    cout << "XOR 2 3" << endl;
    cin >> x23;
    x13 = x12 ^ x23;
    cout << "AND 1 2" << endl;
    cin >> a12;
    cout << "AND 2 3" << endl;
    cin >> a23;
    cout << "AND 1 3" << endl;
    cin >> a13;

    int s12 = x12 + 2 * a12;
    int s23 = x23 + 2 * a23;
    int s13 = x13 + 2 * a13;

    vector<int> a(n + 1);
    a[3] = (s13 - s12 + s23) / 2;
    a[2] = s23 - a[3];
    a[1] = s13 - a[3];

    for (int i = 4; i <= n; i++) {
        cout << "XOR 1" << ' ' << i << endl;
        int x;
        cin >> x;
        a[i] = x ^ a[1];
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}