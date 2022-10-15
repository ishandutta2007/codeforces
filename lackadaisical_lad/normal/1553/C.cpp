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
    string s;
    cin >> s;
    int topkek = 1 << 10;
    int best = 10;
    for (int mask = 0; mask < topkek; mask++) {
        string t = s;
        vector<int> cnt(2), rem(2, 5);
        for (int i = 0; i < 10; i++) {
            if (t[i] == '?') {
                t[i] = char('0' + (mask >> i & 1));
            }
            cnt[i % 2] += t[i] - '0';
            rem[i % 2]--;
            if (cnt[0] > cnt[1] + rem[1] || cnt[1] > cnt[0] + rem[0]) {
                best = min(best, i + 1);
                break;
            } 
        }
    }
    cout << best << '\n';
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