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

const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = (i ? b[i - 1] : 0) + (s[i] == '(' ? 1 : -1);
    }
    if (b[n - 1]) {
        cout << "0\n1 1\n";
        return;
    }
    int best = 0;
    int x, y;
    int low = *min_element(b.begin(), b.end());
    for (int it = low - 2; it <= low + 2; it++) {
        vector<array<int, 3>> dp(n + 1, array<int, 3>{-1, -1, -1});
        vector<array<int, 3>> way(n + 1, array<int, 3>{-1, -1, -1});
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i - 1] < it) {
                if (dp[i - 1][1] > -1) {
                    dp[i][1] = dp[i - 1][1] + (b[i - 1] + 2 == it);
                    way[i][1] = 2;
                }
                if (s[i - 1] == ')' && dp[i - 1][0] > -1 && dp[i - 1][0] + (b[i - 1] + 2 == it) > dp[i][1]) {
                    dp[i][1] = dp[i - 1][0] + (b[i - 1] + 2 == it);
                    way[i][1] = 1;
                }
            } else {
                // no change
                if (dp[i - 1][0] > -1) {
                    dp[i][0] = dp[i - 1][0] + (b[i - 1] == it);
                    way[i][0] = 2;
                }
                if (dp[i - 1][1] > -1) {
                    dp[i][1] = dp[i - 1][1] + (b[i - 1] + 2 == it);
                    way[i][1] = 2;
                }
                if (dp[i - 1][2] > -1) {
                    dp[i][2] = dp[i - 1][2] + (b[i - 1] == it);
                    way[i][2] = 2;
                }
                // close interval
                if (s[i - 1] == '(' && dp[i - 1][1] > -1 && dp[i - 1][1] + (b[i - 1] == it) > dp[i][2]) {
                    dp[i][2] = dp[i - 1][1] + (b[i - 1] == it);
                    way[i][2] = 1;
                }
                // start interval
                if (s[i - 1] == ')' && dp[i - 1][0] > -1 && dp[i - 1][0] + (b[i - 1] + 2 == it) > dp[i][1]) {
                    dp[i][1] = dp[i - 1][0] + (b[i - 1] + 2 == it);
                    way[i][1] = 1;
                }
            }
        }
        if (dp[n][0] > best) {
            best = dp[n][0];
            x = y = 1;
        }
        if (dp[n][2] > best) {
            best = dp[n][2];
            int state = 2;
            for (int i = n; i >= 1; i--) {
                if (way[i][state] == 1) {
                    if (state == 2) {
                        y = i;
                    } else {
                        x = i;
                    }
                    state--;
                }
            }
        }
    }
    
    for (int it = low - 2; it <= low + 2; it++) {
        vector<array<int, 3>> dp(n + 1, array<int, 3>{-1, -1, -1});
        vector<array<int, 3>> way(n + 1, array<int, 3>{-1, -1, -1});
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i - 1] < it) {
                break;
            } else {
                // no change
                if (dp[i - 1][0] > -1) {
                    dp[i][0] = dp[i - 1][0] + (b[i - 1] == it);
                    way[i][0] = 2;
                }
                if (dp[i - 1][1] > -1 && b[i - 1] - 2 >= it) {
                    dp[i][1] = dp[i - 1][1] + (b[i - 1] - 2 == it);
                    way[i][1] = 2;
                }
                if (dp[i - 1][2] > -1) {
                    dp[i][2] = dp[i - 1][2] + (b[i - 1] == it);
                    way[i][2] = 2;
                }
                // close interval
                if (s[i - 1] == ')' && dp[i - 1][1] > -1 && dp[i - 1][1] + (b[i - 1] == it) > dp[i][2]) {
                    dp[i][2] = dp[i - 1][1] + (b[i - 1] == it);
                    way[i][2] = 1;
                }
                // start interval
                if (s[i - 1] == '(' && dp[i - 1][0] > -1 && dp[i - 1][0] + (b[i - 1] - 2 == it) > dp[i][1] && b[i - 1] - 2 >= it) {
                    dp[i][1] = dp[i - 1][0] + (b[i - 1] - 2 == it);
                    way[i][1] = 1;
                }
            }
        }
        if (dp[n][0] > best) {
            best = dp[n][0];
            x = y = 1;
        }
        if (dp[n][2] > best) {
            best = dp[n][2];
            int state = 2;
            for (int i = n; i >= 1; i--) {
                if (way[i][state] == 1) {
                    if (state == 2) {
                        y = i;
                    } else {
                        x = i;
                    }
                    state--;
                }
            }
        }
    }
    
    cout << best << '\n';
    cout << x << ' ' << y << '\n';
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