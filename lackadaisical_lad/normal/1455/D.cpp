#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
    int ans = 1e9;
    vector<int> a(n);
    int ok = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            ok &= a[i] >= a[i - 1];
        }
    }
    if (ok) {
        cout << "0\n";
        return;
    }
    for (int it = 0; it < n; it++) {
        vector<pair<int, int>> b(n);
        vector<int> num(n);
        int bad = 0;
        vector<int> c = a;
        int heh = a[it];
        for (int j = 0; j < n; j++) {
            b[j] = {a[j], j};
            c[j] = a[j];
            if (it == j) {
                if (a[j] <= x) {
                    bad = 1;
                }
                b[j].first = x;
                c[j] = x;
            }
            num[b[j].second] = b[j].first;
        }
        sort(b.begin(), b.end());
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[b[i].second] = i;
        }

        int len = 0;
        for (int v = it;;) {
            if (num[v] > heh) {
                bad = 1;
            }
            int nxt = p[v];
            c[nxt] = num[v];
            if (nxt == it) break;
            if (num[nxt] != num[v]) len++;
            if (num[nxt] < num[v]) bad = 1;
            v = nxt;
        }
        if (bad) continue;
        int ok = 1;
        for (int i = 1; i < n; i++) {
            ok &= c[i] >= c[i - 1];
        }
        if (ok) {
            ans = min(ans, len + 1);
        }
    }   

    if (ans == 1e9) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
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