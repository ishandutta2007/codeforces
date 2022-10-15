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
    vector<int> a(n), pos(n), fix(n);    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
        fix[(i - a[i] + n) % n]++; 
    }
    vector<int> ans;
    for (int it = 0; it < n; it++) {
        if (fix[it] < n - m * 2) {
            continue;
        }
        // brute
        int cycles = 0;
        vector<int> used(n);
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            cycles++;
            int v = (a[i] + it) % n;
            while (!used[v]) {
                used[v] = 1;
                v = (a[v] + it) % n;
            }
        }
        if (n - cycles <= m) {
            ans.push_back(it);
        } 
    }
    cout << ans.size() << ' ';
    for (int i : ans) {
        cout << i << ' ';
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