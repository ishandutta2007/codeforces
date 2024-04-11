
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

// dp[mask][i] = probability Ivan wins if alive
// participants according to mask, and i is the index of the champion

const int N = 19;
int n;
double p[N][N], dp[1 << N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
        cin >> p[i][j];
    }
    rep(mask, 1, 1 << n) {
        if((mask & 1) == 0) continue;
        int k = __builtin_popcount(mask);
        if(k == 1) {
            dp[mask][0] = 1;
            continue;
        }
        rep(i, 0, n) {
            if((mask >> i) & 1) {
                rep(j, 0, n) {
                    if(i != j && ((mask >> j) & 1)) {
                        dp[mask][i] = max(dp[mask][i], p[i][j] * dp[mask - (1 << j)][i] + p[j][i] * dp[mask - (1 << i)][j]);
                    }
                }
            }
        }
    }
    double ans = 0;
    rep(i, 0, n) {
        ans = max(ans, dp[(1 << n) - 1][i]);
    }
    cout << fixed << setprecision(8);
    cout << ans << '\n';
}