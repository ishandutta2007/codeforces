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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }

    vector<int> cycle;
    vector<int> used(n);
    int i;
    for (i = 0; !used[i]; i = a[i]) {
        cycle.push_back(i);
        used[i] = 1;
    }
    vector<int> ans;
    auto pos = find(cycle.begin(), cycle.end(), i);
    for (auto it = pos; it != cycle.end(); it++) {
        ans.push_back(*it + 1);
    }
    cout << ans.size() << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}