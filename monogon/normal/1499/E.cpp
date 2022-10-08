
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int M = 998244353;
const int N = 1005;

ll dp[N][N][3];

ll cnt(const string &s) {
    int j = 1;
    int n = s.length();
    ll ans = 0;
    rep(i, 1, n) {
        j = max(j, i + 1);
        while(j < n && s[j] != s[j - 1]) j++;
        ans = (ans + j - i) % M;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x, y;
    cin >> x >> y;
    x = "$" + x;
    y = "$" + y;
    int n = x.length(), m = y.length();
    ll ans = 0;
    for(int i = n; i >= 1; i--) for(int j = m; j >= 1; j--) {
        dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1;
        if(i < n) {
            dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % M;
            if(x[i] != x[i - 1]) {
                dp[i][j][1] = (dp[i][j][1] + dp[i + 1][j][1]) % M;
            }
            if(x[i] != y[j - 1]) {
                dp[i][j][2] = (dp[i][j][2] + dp[i + 1][j][1]) % M;
            }
        }
        if(j < m) {
            dp[i][j][0] = (dp[i][j][0] + dp[i][j + 1][2]) % M;
            if(y[j] != x[i - 1]) {
                dp[i][j][1] = (dp[i][j][1] + dp[i][j + 1][2]) % M;
            }
            if(y[j] != y[j - 1]) {
                dp[i][j][2] = (dp[i][j][2] + dp[i][j + 1][2]) % M;
            }
        }
        // cout << i << ' ' << j << ":\t" << dp[i][j][0] << ' ' << dp[i][j][1] << ' ' << dp[i][j][2] << '\n';
        ans = (ans + dp[i][j][0] - 1) % M;
    }
    ll sub = (cnt(x) * m) % M;
    sub = (sub + cnt(y) * n) % M;
    ans -= sub;

    ans = (ans + M) % M;
    cout << ans << '\n';
}