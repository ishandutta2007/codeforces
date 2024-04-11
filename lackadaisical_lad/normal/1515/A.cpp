#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

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
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += w[i];
        if (s == x) {
            s = s - w[i] + w[n - 1];
            swap(w[n - 1], w[i]);
        }
    }
    if (s == x) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << w[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}