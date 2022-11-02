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

int t, n, k;
vi a;
vvi dp;

void solve() {
    cin >> n >> k;
    a.rsz(n);
    F0R(i, n) {cin >> a[i]; a[i]--;}
    dp.clear(); dp.rsz(n+1, vi(n+1, 0));
    F0R(i, n) {
        F0R(j, i+1) {
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]);
            if (a[i]==j) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);
        }
    }
    R0F(i, n+1) if (dp[n][i]>=k) {
        cout << n-i << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}