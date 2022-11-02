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

int t, n, k, u, v;
vvi adj;
vi dep, part;

void dfs(int i, int p, int d) {
    dep[i]=d;
    for (int nb : adj[i]) if (nb != p) {
        part[nb]=part[i];
        dfs(nb, i, d+1);
    }
}

ll calc(int i) {
    // cout << "From " << i << '\n';
    dep.clear(); dep.rsz(n, 0);
    part.clear(); part.rsz(n, i);
    for (int nb : adj[i]) {
        part[nb]=nb;
        dfs(nb, i, 1);
    }
    ll ans = 0;
    FOR(d, 1, n) {
        map<int, ll> freq;
        F0R(i, n) if (dep[i]==d) freq[part[i]]++;
        if (freq.size()<k) break;
        vll vals;
        for (auto p : freq) vals.pb(p.S);
        vvll dp(vals.size(), vll(k, 0));
        dp[0][0]=vals[0];
        FOR(i, 1, vals.size()) {
            dp[i][0]=(vals[i] + dp[i-1][0])%MOD;
            FOR(j, 1, k) {
                dp[i][j] = (dp[i-1][j] + vals[i]*dp[i-1][j-1])%MOD;
            }
        }
        ans = (ans + dp[vals.size()-1][k-1])%MOD;
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    adj.clear(); adj.rsz(n);
    F0R(i, n-1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    if (k==2) {
        cout << n * (n-1) / 2 << '\n';
        return;
    }
    ll ans = 0;
    F0R(i, n) ans = (ans + calc(i))%MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}