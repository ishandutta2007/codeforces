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

const int N = 4001;
const int M = 26;

int dp[N][N];
int last[N][M];
int lost[N][M];

void solve() {
    int ti, td, tr, ts;
    cin >> ti >> td >> tr >> ts;
    tr = min(tr, ti + td);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < N; i++) {
        fill(dp[i], dp[i] + N, 1e9);
    }
    dp[0][0] = 0;
    for (int i = 1; i <= s.length(); i++) {
        dp[i][0] = td * i;
    }
    for (int j = 1; j <= t.length(); j++) {
        dp[0][j] = ti * j;
    }
    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i - 1] - 'a' == j) {
                last[i][j] = i;
            } else {
                last[i][j] = last[i - 1][j];
            }
        }
    }
    for (int i = 1; i < t.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (t[i - 1] - 'a' == j) {
                lost[i][j] = i;
            } else {
                lost[i][j] = lost[i - 1][j];
            }
        }
    }

    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            dp[i][j] = min(dp[i][j - 1] + ti, dp[i - 1][j] + td);
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + tr);
            int pos1 = last[i - 1][t[j - 1] - 'a'];
            if (pos1 && j >= 2) {
                dp[i][j] = min(dp[i][j], dp[pos1 - 1][j - 2] + td * (i - pos1 - 1) + ts + tr * (s[i - 1] != t[j - 2]));
            }
            int pos2 = lost[j - 1][s[i - 1] - 'a'];
            if (pos2 && i >= 2) {
                dp[i][j] = min(dp[i][j], dp[i - 2][pos2 - 1] + ti * (j - pos2 - 1) + ts + tr * (t[j - 1] != s[i - 2]));
            }
            if (pos1 && pos2 && i >= 2 && j >= 2) {
                dp[i][j] = min(dp[i][j], dp[pos1 - 1][pos2 - 1] + td * (i - pos1 - 1) + ti * (j - pos2 - 1) + ts);
            }
        }
    }
    cout << dp[s.length()][t.length()] << endl;
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