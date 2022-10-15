#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
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
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cout << "? 0 " << i << endl;
        cin >> x[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        cout << "? " << i << ' ' << i + 1 << endl;
        cin >> y[i];
    }

    set<vector<int>> ans;
    for (int f = 0; f < n; f++) {
        vector<int> p(n), b(n);
        int bad = 0;
        for (int i = 0; i < n; i++) {
            b[i] = f ^ x[i];
            if (b[i] >= n) {
                bad = 1;
                break;
            }
            p[b[i]] = i;
        }
        for (int i = 0; i + 1 < n && !bad; i++) {
            if ((p[i] ^ b[i + 1]) != y[i]) {
                bad = 1;
            }
        }
        if (bad) continue;
        if (p[0] == f) {
            ans.insert(p);
        }
    }
    cout << "!" << endl;
    cout << ans.size() << endl;
    auto p = *ans.begin();
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}