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

int t, n, m, u, v;
vvi adj;
vi dist, order, ans;
vb vis;
queue<int> q;

void solve() {
    cin >> n >> m;
    adj.clear(); dist.clear(); order.clear(); ans.clear(); vis.clear();
    adj.rsz(n);
    F0R(i, m) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }
    vis.rsz(n, false);
    dist.rsz(n, 1e9);
    dist[0]=0;
    q.push(0);
    while (! q.empty()) {
        u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        order.pb(u);
        for (int nb : adj[u]) if (!vis[nb] && dist[nb]>dist[u]+1) {
            q.push(nb);
            dist[nb]=dist[u]+1;
        }
    }
    reverse(all(order));
    ans.rsz(n);
    F0R(i, n) {
        ans[i]=dist[i];
        for (int nb : adj[i]) ans[i]=min(ans[i], dist[nb]);
    }
    for (int i : order) {
        for (int nb : adj[i]) if (dist[nb]>dist[i]) ans[i]=min(ans[i], ans[nb]);
    }
    F0R(i, n) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}