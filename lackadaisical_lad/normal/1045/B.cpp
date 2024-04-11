#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> cand;
    if (a[0] - (m - a[n - 1]) >= 0) {
        cand.push_back(a[0] - (m - a[n - 1]));
    }
    for (int i = 0; i < n; i++) {
        if (a[i] + a[0] < m)
            cand.push_back(a[i] + a[0]);
    }

    int it = 0;
    int cur = -1;
    ll h1 = 0, h2 = 0;
    vector<int> hit(cand.size());
    for (int i = 0; i < cand.size(); i++) {
        int x = cand[i];
        while (it < n && a[it] <= x) {
            (h1 += binpow(2, a[it])) %= MOD;
            (h2 = h2 * binpow(2, a[it] - cur) + 1) %= MOD;
            cur = a[it];
            it++;
        }
        (h2 *= binpow(2, x - cur)) %= MOD;
        cur = x;
        if (h1 == h2) {
            hit[i]++;
        }
    }
    
    it = n - 1;
    cur = -1;
    h1 = 0, h2 = 0;
    for (int i = 0; i < n; i++) {
        a[i] = m - a[i] - 1;
    }
    for (int i = (int)cand.size() - 1; i >= 0; i--) {
        int x = m - cand[i] - 2;
        while (it >= 0 && a[it] <= x) {
            (h1 += binpow(2, a[it])) %= MOD;
            (h2 = h2 * binpow(2, a[it] - cur) + 1) %= MOD;
            cur = a[it];
            it--;
        }
        (h2 *= binpow(2, x - cur)) %= MOD;
        cur = x;
        if (h1 == h2) {
            hit[i]++;
        }
    }
    
    set<int> ans;
    for (int i = 0; i < cand.size(); i++) {
        if (hit[i] == 2) {
            ans.insert(cand[i]);
        }
    }
    cout << ans.size() << '\n';
    for (int rem : ans) {
        cout << rem << ' ';
    }
    cout << '\n';
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