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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> cnta(26), cntb(26);
    for (char c : a) {
        cnta[c - 'a']++;
    }
    for (char c : b) {
        cntb[c - 'a']++;
    }
    for (int i = 0; i < 25; i++) {
        if (cnta[i] < cntb[i]) {
            cout << "No\n";
            return;
        }
        int delta = cnta[i] - cntb[i];
        if (delta % k) {
            cout << "No\n";
            return;
        }
        cnta[i + 1] += delta;
        cnta[i] -= delta;
    }
    if (cnta == cntb) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}