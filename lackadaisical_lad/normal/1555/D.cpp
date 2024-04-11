#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
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

const int N = 2e5 + 5;
int pref[N][3][3];

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int i = 1; i <= n; i++) {
                pref[i][x][y] = pref[i - 1][x][y];
                if (i % 3 == x && s[i - 1] - 'a' == y) {
                    pref[i][x][y]++;
                }
            }
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        vector<int> p{0, 1, 2};
        int mt = 0;
        do {
            int cur = 0;
            for (int x = 0; x < 3; x++) {
                cur += pref[r][x][p[x]] - pref[l - 1][x][p[x]];
            }
            mt = max(mt, cur);
        } while (next_permutation(p.begin(), p.end()));
        cout << r - l + 1 - mt << '\n';
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