#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

int t, m;
vvi a;

void solve() {
    cin >> m;
    a.clear(); a.rsz(2, vi(m));
    F0R(i, 2) F0R(j, m) cin >> a[i][j];
    if (m==1) {
        cout << 0 << '\n';
        return;
    }
    FOR(j, 1, m) a[1][j] += a[1][j-1];
    R0F(j, m-1) a[0][j] += a[0][j+1];
    int ans = 1e9+1e8;
    ans = min(ans, a[0][1]);
    ans = min(ans, a[1][m-2]);
    FOR(i, 1, m-1) ans = min(ans, max(a[0][i+1], a[1][i-1]));
    cout << ans << '\n';
    // int dp[2][m][2], dp2[m];
    // dp[1][m-1][0]=a[1][m-1];
    // dp[1][m-1][1]=0;
    // dp[0][m-1][0]=a[0][m-1];
    // dp[0][m-1][1]=0;
    // dp2[m-1]=0;
    // R0F(i, m-1) {
    //     dp[1][i][0]=a[1][i];
    //     dp[1][i][1]=0;
    //     dp[0][i][0]=a[0][i]+dp[0][i+1][0];
    //     dp[0][i][1]=min(max(dp[1][i][0], dp[0][i+1][1]), max(dp[1][i][1], dp[0][i+1][0]));
    // }
    // F0R(i, 2) {
    //     F0R(j, m) cout << '(' << dp[i][j][0] << ", " << dp[i][j][1] << ") ";
    //     cout << '\n';
    // }
    // cout << dp[0][0][1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}