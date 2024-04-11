
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int N = 3005, M = 998244353;
string s, t;
int n, m;
ll dp[N][N];

bool match(char a, char b) {
    return b == '*' || a == b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    rep(i, m, n) t.push_back('*');
    for(int i = 0; i <= n; i++) dp[0][i] = 1;
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            if(match(s[len - 1], t[i])) {
                dp[len][i] += dp[len - 1][i + 1];
            }
            if(match(s[len - 1], t[i + len - 1])) {
                dp[len][i] += dp[len - 1][i];
            }
            dp[len][i] %= M;
        }
    }
    ll ans = 0;
    rep(i, m, n + 1) ans = (ans + dp[i][0]) % M;
    cout << ans << endl;
}