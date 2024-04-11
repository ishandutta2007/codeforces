#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    VVI dp(n, VI(m));
    rep(i, n) rep(j, m) {
        if (i) chmax(dp[i][j], dp[i-1][j] - 1);
        if (j) chmax(dp[i][j], dp[i][j-1] - 1);
        if (a[i] == b[j]) {
            if (i && j) chmax(dp[i][j], max(4 - 2, dp[i-1][j-1] - 2 + 4));
            else chmax(dp[i][j], 4 - 2);
        }
    }
    int ans = 0;
    rep(i, n) rep(j, m) chmax(ans, dp[i][j]);
    //rep(i, n) rep(j, m) cout << dp[i][j] << " \n"[j + 1 == m];
    cout << ans << '\n';
}