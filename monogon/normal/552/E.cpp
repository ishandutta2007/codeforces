
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// dp[i][len] -> parse the substring from i of length len.
// if len = 0, 0. if len = 1, digit
// if + exists, split and add
// if no plus exists, multiply

const int N = 2505;
string s;
int n;
ll num[N], dp[N][N];
int p[N][N], p2[N][N];
char op[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = (s.length() + 1) / 2;
    rep(i, 0, n) {
        num[i] = s[2 * i] - '0';
        if(i < n - 1) {
            op[i] = s[2 * i + 1];
        }
    }
    rep(len, 0, n + 1) {
        rep(i, 0, n - len + 1) {
            if(len == 0) {
                p[i][len] = p2[i][len] = -1;
                dp[i][len] = 0;
            }else if(len == 1) {
                p[i][len] = p2[i][len] = -1;
                dp[i][len] = num[i];
            }else {
                p[i][len] = p[i + 1][len - 1];
                p2[i][len] = p2[i + 1][len - 1];
                if(op[i] == '+') {
                    p[i][len] = i;
                    if(p2[i][len] == -1) p2[i][len] = i;
                }
                if(p[i][len] != -1) {
                    dp[i][len] = dp[i][p[i][len] - i + 1] + dp[p[i][len] + 1][len - p[i][len] + i - 1];
                }else {
                    dp[i][len] = num[i] * dp[i + 1][len - 1];
                }
            }
        }
    }
    ll ans = num[0];
    rep(i, 0, n) {
        rep(j, i, n) {
            ll x = 0, y = dp[i][j - i + 1], z = 0;
            int ix = p2[0][i + 1];
            int iz = p[j][n - j];
            if(ix == -1) {
                y *= max(1LL, dp[0][i]);
            }else {
                y *= max(1LL, dp[ix + 1][i - ix - 1]);
                x = dp[0][ix + 1];
            }
            if(iz == -1) {
                y *= max(1LL, dp[j + 1][n - j - 1]);
            }else {
                y *= max(1LL, dp[j + 1][iz - j]);
                z = dp[iz + 1][n - iz - 1];
            }
            ll res = x + y + z;
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
}