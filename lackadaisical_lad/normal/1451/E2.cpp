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
    vector<int> x(n + 1);
    vector<int> used(1 << 16);
    int pos1 = -1, pos2 = -1;
    used[0] = 1;
    for (int i = 2; i <= n; i++) {
        cout << "XOR 1 " << i << endl;
        cin >> x[i];
        if (used[x[i]]) {
            pos1 = used[x[i]];
            pos2 = i;
        }
        used[x[i]] = i;
    }
    if (pos1 == -1) {
        for (int i = 2; i <= n; i++) {
            if (x[i] == 1) {
                pos1 = i;
            }
            if (x[i] == 2) {
                pos2 = i;
            }
        }
        int a, b;
        cout << "AND 1 " << pos1 << endl;
        cin >> a;
        cout << "AND 1 " << pos2 << endl;
        cin >> b;
        if (b % 2) {
            a |= 1;
        } else {
            a &= (n - 2); 
        }
        cout << "! " << a << ' ';
        for (int i = 2; i <= n; i++) {
            cout << (a ^ x[i]) << ' ';
        }
        cout << endl;
        return;
    }
    vector<int> val(n + 1);
    cout << "AND " << pos1 << ' ' << pos2 << endl;
    int a;
    cin >> a;
    val[pos1] = val[pos2] = a;
    for (int i = 1; i <= n; i++) {
        if (i == pos1 || i == pos2) continue;
        val[i] = a ^ x[pos1] ^ x[i];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << val[i] << ' ';
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