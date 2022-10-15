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
    vector<int> len(3);
    for (int i = 0; i < 3; i++) {
        cin >> len[i];
    }
    ll s = 0;
    vector<vector<int>> a(3);
    vector<int> tot;
    for (int i = 0; i < 3; i++) {
        a[i].resize(len[i]);
        for (int j = 0; j < len[i]; j++) {
            cin >> a[i][j];
            s += a[i][j];
            tot.push_back(a[i][j]);
        }
        sort(a[i].begin(), a[i].end());
    }
    sort(tot.begin(), tot.end());
    ll best = LLONG_MIN;
    for (int i = 0; i < 3; i++) {
        if (len[i] == 1) {
            best = max(best, s - a[i][0] * 2);
            continue;
        }
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            best = max(best, s - a[i][0] * 2 - a[j][0] * 2);
        }
        ll cur = s;
        for (int x : a[i]) {
            cur -= x * 2;
        }
        best = max(best, cur);
    }

    cout << best << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}