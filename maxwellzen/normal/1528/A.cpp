#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

int t, n, u, v;
vvi adj;
vvll dp, b;

ll rec(int i, int par, int x) {
    if (dp[i][x] != -1) return dp[i][x];
    ll ans = 0;
    for (int nb : adj[i]) if (nb != par) ans += max(rec(nb, i, 0)+abs(b[i][x]-b[nb][0]), rec(nb, i, 1)+abs(b[i][x]-b[nb][1]));
    dp[i][x]=ans;
    return ans;
}
 
void solve() {
    cin >> n;
    adj.clear(); b.clear(); dp.clear();
    adj.rsz(n);
    b.rsz(n, vll(2));
    dp.rsz(n, vll(2, -1));
    F0R(i, n) cin >> b[i][0] >> b[i][1];
    F0R(i, n-1) {
        cin >> u >> v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    cout << max(rec(0, 0, 0), rec(0, 0, 1)) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}