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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.length(); i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    int cur = s.length();
    for (int i = t.length() - 1; i >= 0; i--) {
        int c = t[i] - 'a';
        int nxt = lower_bound(pos[c].begin(), pos[c].end(), cur) - pos[c].begin() - 1;
        while (nxt >= 0 && (cur - pos[c][nxt]) % 2 == 0) {
            nxt--;
        }
        if (nxt < 0) {
            cout << "NO\n";
            return;
        }
        cur = pos[c][nxt];
    }
    cout << "YES\n";
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