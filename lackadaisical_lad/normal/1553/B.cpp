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
    int n = s.length();
    int m = t.length();
    vector<vector<int>> can(n + 1, vector<int>(m + 1));
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        can[i][0] = 1;
        for (int j = 1; j <= m && i + j <= s.length(); j++) {
            can[i][j] = can[i][j - 1] & (s[i + j - 1] == t[j - 1]);
        }
    }
    // cout << can[1][3] << endl;
    reverse(t.begin(), t.end());
    for (int i = 0; i < s.length(); i++) {
        int ok = 1;
        for (int j = 1; j <= min(t.length(), s.length()); j++) {
            ok &= s[i + j - 1] == t[j - 1];
            int pos = i + j * 2 - (int)t.length() - 1;
            if (ok && (j == t.length() || pos >= 0 && can[pos][t.length() - j])) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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