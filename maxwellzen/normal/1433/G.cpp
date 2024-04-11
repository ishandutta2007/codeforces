#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> iset;

typedef long long ll;
typedef long double db;
typedef string str;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<str> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define arr array
#define nl '\n'
#define debug(x) cout<<#x<<" = "<<x<<nl
#define print(x) cout<<x<<nl

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}

int n, m, k, u, v, w;
vector<vpi> adj;
vpi routes, edges;
vvi dist;
vb vis;

void solve() {
    cin >> n >> m >> k;
    adj.rsz(n);
    dist.rsz(n, vi(n, 1e9));
    vis.rsz(n, false);
    F0R(i, m) {
        cin >> u >> v >> w; u--; v--;
        edges.pb(mp(u, v));
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    F0R(i, k) {
        cin >> u >> v; u--; v--;
        routes.pb(mp(u, v));
    }
    F0R(i, n) {
        pqg<pi> pq;
        dist[i][i]=0;
        fill(all(vis), false);
        pq.push(mp(0, i));
        while (! pq.empty()) {
            u = pq.top().S;
            pq.pop();
            if (vis[u]) continue;
            vis[u]=true;
            for (pi nb : adj[u]) {
                if (!vis[nb.F] && dist[i][nb.F]>dist[i][u]+nb.S) {
                    dist[i][nb.F]=dist[i][u] + nb.S;
                    pq.push(mp(dist[i][nb.F], nb.F));
                }
            }
        }
    }
    ll ans = 1e18;
    for (pi edge : edges) {
        u = edge.F; v=edge.S;
        ll cur = 0;
        for (pi r : routes) {
            cur += min({dist[r.F][r.S], dist[r.F][u]+dist[v][r.S], dist[r.F][v]+dist[u][r.S]});
        }
        ckmin(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}