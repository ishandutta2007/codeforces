
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

// each number has a number of 2 factors and number of 5 factors
// (x_i, y_i)
// choose subset of k points maximizing
// k = min(sum x_i, sum y_i) <= log2(10^18) = 60

const int N = 205;
int n, k;
ll a;
int x[N], y[N];
int dp[2][N][60 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> a;
        while(a % 2 == 0) {
            a /= 2;
            x[i]++;
        }
        while(a % 5 == 0) {
            a /= 5;
            y[i]++;
        }
    }
    int ans = 0;
    rep(j, 0, k + 1) {
        rep(w, 0, 60 * N) {
            dp[0][j][w] = -1;
        }
    }
    dp[0][0][0] = 0;
    rep(i, 1, n + 1) {
        int b = (i % 2);
        rep(j, 0, k + 1) {
            rep(w, 0, 60 * N) {
                dp[b][j][w] = dp[!b][j][w];
                if(j > 0 && w >= y[i] && dp[!b][j - 1][w - y[i]] != -1) {
                    dp[b][j][w] = max(dp[b][j][w], x[i] + dp[!b][j - 1][w - y[i]]);
                }
                if(j == k) {
                    ans = max(ans, min(w, dp[b][j][w]));
                }
            }
        }
    }
    cout << ans << '\n';
}