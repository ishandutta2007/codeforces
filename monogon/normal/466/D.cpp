
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

// rightmost element => in at most one interval, as the right endpoint
// recurse on first i - 1 elements, knowing we can increment whatever suffix we want
// dp[i][j] => i elements, increment j suffixes
// distance d = h - a[i]
// option: continue all j suffixes, continue only j - 1 suffixes
// another option: start a new interval with right endpoint i, or not
// if we start a new interval, we can choose whether to stop it

// continue all j suffixes
//   start a new interval and end it
//     d = j + 1, j
//   start a new interval and don't end it
//     d = j + 1, j + 1
//   don't start a new interval
//     d = j, j
// continue only j - 1 suffixes
//   j choices of which one to stop
//   start a new interval and don't end it
//     d = j + 1, j
//   don't start a new interval
//     d = j, j - 1

const int N = 2005, M = 1e9 + 7;
int n, h, a[N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    rep(i, 1, n + 1) cin >> a[i];
    dp[0][0] = 1;
    rep(i, 1, n + 1) rep(j, 0, n - i + 1) {
        int d = h - a[i];
        if(d == j + 1) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1] + (j > 0 ? j * dp[i - 1][j] : 0)) % M;
        }else if(d == j) {
            dp[i][j] = (dp[i - 1][j] + (j > 0 ? j * dp[i - 1][j - 1] : 0)) % M;
        }
    }
    cout << dp[n][0] << '\n';
}