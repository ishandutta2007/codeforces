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

ll count(ll n, int pos) {
    ll pw = 1LL << pos;
    ll count = n / (pw * 2) * pw;
    n %= pw * 2;
    count += min(pw, n);
    return count;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> p(n), inv(n);
    for (int i = 0; i < n; i++) {
        p[a[i].second] = i;
        inv[i] = a[i].second;
    }

    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = p[i] + 1; j <= i; j++) {
            int x = inv[j];
            int y = i;
            ans.emplace_back(x + 1, y + 1);
            swap(inv[p[i]], inv[j]);
            swap(p[x], p[y]);
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
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