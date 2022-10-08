
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

const int N = 105;
int t, n, m;
ll a[N][N], dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n) rep(j, 0, m) {
            cin >> a[i][j];
            a[i][j] += (n + m) - (i + j);
        }
        ll ans = LLONG_MAX;
        rep(i, 0, n) rep(j, 0, m) {
            ll val = a[i][j];
            rep(x, 0, n) rep(y, 0, m) {
                dp[x][y] = LLONG_MAX;
                if(a[x][y] >= val) {
                    if(x == 0 && y == 0) {
                        dp[x][y] = a[x][y] - val;
                    }else {
                        if(x > 0 && dp[x - 1][y] < LLONG_MAX) {
                            dp[x][y] = dp[x - 1][y] + a[x][y] - val;
                        }
                        if(y > 0 && dp[x][y - 1] < LLONG_MAX) {
                            dp[x][y] = min(dp[x][y], dp[x][y - 1] + a[x][y] - val);
                        }
                    }
                }
            }
            ans = min(ans, dp[n - 1][m - 1]);
        }
        cout << ans << '\n';
    }
}