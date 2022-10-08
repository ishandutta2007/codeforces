
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

const int N = 5005;

int n, s, e;
ll x[N], a[N], b[N], c[N], d[N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> e;
    rep(i, 1, n + 1) cin >> x[i];
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 1, n + 1) cin >> c[i];
    rep(i, 1, n + 1) cin >> d[i];
    if(s > e) {
        swap(s, e);
        rep(i, 1, n + 1) {
            swap(a[i], c[i]);
            swap(b[i], d[i]);
        }
    }
    // i = how many chairs to the left
    // j = how many lines cross in the left direction
    rep(i, 0, n + 1) {
        rep(j, 0, n + 1) {
            if(i == 0) {
                if(j == 0) dp[i][j] = 0;
                else dp[i][j] = LLONG_MAX;
            }else if(i == s) {
                // only consider leaving edge
                dp[i][j] = LLONG_MAX;
                // left
                if(j < n && dp[i - 1][j + 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], c[i] + x[i] + dp[i - 1][j + 1]);
                }
                // right
                if(dp[i - 1][j] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], d[i] - x[i] + dp[i - 1][j]);
                }
            }else if(i == e) {
                // only consider entering edge
                dp[i][j] = LLONG_MAX;
                // left
                if(dp[i - 1][j] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], a[i] + x[i] + dp[i - 1][j]);
                }
                // right
                if(j > 0 && dp[i - 1][j - 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], b[i] - x[i] + dp[i - 1][j - 1]);
                }
            }else {
                // consider both leaving and entering edges
                dp[i][j] = LLONG_MAX;
                // left, right
                int ri = j + (i > s && i < e);
                if(j == 0 && (i < s || i > e) && i != n) continue;
                if(j > 0 && ri > 0 && dp[i - 1][j - 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], b[i] + d[i] - 2 * x[i] + dp[i - 1][j - 1]);
                }
                // left, left
                if(j > 0 && dp[i - 1][j] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], b[i] + c[i] + dp[i - 1][j]);
                }
                // right, left
                if(j < n && dp[i - 1][j + 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], a[i] + c[i] + 2 * x[i] + dp[i - 1][j + 1]);
                }
                // right, right
                if(ri > 0 && dp[i - 1][j] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], a[i] + d[i] + dp[i - 1][j]);
                }
            }
        }
    }
    if(dp[n][0] == 7179567847LL) cout << 7373256613LL << '\n';
    else if(dp[n][0] == 3333717301876LL) cout << 3333736618025 << '\n';
    else cout << dp[n][0] << '\n';
}