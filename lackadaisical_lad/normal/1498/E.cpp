#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 998'244'353;

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
    vector<pair<int, int>> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i].first;
        k[i].second = i + 1;
    }
    sort(k.begin(), k.end());
    for (int j = 0; j < n; j++)
    for (int i = n - 1; i > j; i--) {
        cout << "? " << k[i].second << ' ' << k[j].second << endl;
        string ans;
        cin >> ans;
        if (ans == "Yes") {
            cout << "! " << k[i].second << ' ' << k[j].second << endl;
            return;
        }
    }
    cout << "! 0 0" << endl;
}

int main() {
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
}