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

const int N = 253;

int dp[N][N][N];

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, 26>> jump(n + 2);
    jump[n].fill(n);
    jump[n + 1].fill(n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (s[i] - 'a' == j) {
                jump[i][j] = i;
            } else {
                jump[i][j] = jump[i + 1][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fill(dp[i][j], dp[i][j] + N, n);
        }
    }
    dp[0][0][0] = -1;
    array<string, 3> words;
    words.fill("");
    while (q--) {
        char op;
        int id;
        cin >> op >> id;
        id--;
        if (op == '+') {
            char c;
            cin >> c;
            words[id] += c;
            if (id == 0)
                for (int i = (id == 0 ? words[0].length() : 0); i <= words[0].length(); i++) {
                    for (int j = (id == 1 ? words[1].length() : 0); j <= words[1].length(); j++) {
                        for (int k = (id == 2 ? words[2].length() : 0); k <= words[2].length(); k++) {
                            dp[i][j][k] = n;
                            if (i) dp[i][j][k] = min(dp[i][j][k], jump[dp[i - 1][j][k] + 1][words[0][i - 1] - 'a']);
                            if (j) dp[i][j][k] = min(dp[i][j][k], jump[dp[i][j - 1][k] + 1][words[1][j - 1] - 'a']);
                            if (k) dp[i][j][k] = min(dp[i][j][k], jump[dp[i][j][k - 1] + 1][words[2][k - 1] - 'a']);
                        }
                    }
                }
            if (id == 1)
                    for (int j = (id == 1 ? words[1].length() : 0); j <= words[1].length(); j++) {
                for (int i = (id == 0 ? words[0].length() : 0); i <= words[0].length(); i++) {
                        for (int k = (id == 2 ? words[2].length() : 0); k <= words[2].length(); k++) {
                            dp[i][j][k] = n;
                            if (i) dp[i][j][k] = min(dp[i][j][k], jump[dp[i - 1][j][k] + 1][words[0][i - 1] - 'a']);
                            if (j) dp[i][j][k] = min(dp[i][j][k], jump[dp[i][j - 1][k] + 1][words[1][j - 1] - 'a']);
                            if (k) dp[i][j][k] = min(dp[i][j][k], jump[dp[i][j][k - 1] + 1][words[2][k - 1] - 'a']);
                        }
                    }
                }
            if (id == 2)
                        for (int k = (id == 2 ? words[2].length() : 0); k <= words[2].length(); k++) {
                for (int i = (id == 0 ? words[0].length() : 0); i <= words[0].length(); i++) {
                    for (int j = (id == 1 ? words[1].length() : 0); j <= words[1].length(); j++) {
                            dp[i][j][k] = n;
                            if (i) dp[i][j][k] = min(dp[i][j][k], jump[dp[i - 1][j][k] + 1][words[0][i - 1] - 'a']);
                            if (j) dp[i][j][k] = min(dp[i][j][k], jump[dp[i][j - 1][k] + 1][words[1][j - 1] - 'a']);
                            if (k) dp[i][j][k] = min(dp[i][j][k], jump[dp[i][j][k - 1] + 1][words[2][k - 1] - 'a']);
                        }
                    }
                }
        } else {
            words[id].pop_back();
        }
        cout << (dp[words[0].length()][words[1].length()][words[2].length()] < n ? "YES\n" : "NO\n");
        // cout << dp[words[0].length()][words[1].length()][words[2].length()] << endl;
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