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

int n, u, v;
vvi adj;
vi cyc, path;
vb vis;

bool cycle(int i, int p) {
    if (vis[i]) {
        F0R(j, path.size()) {
            if (path[j]==i) {
                FOR(k, j, path.size()) cyc.pb(path[k]);
                return true;
            }
        }
    }
    vis[i]=true;
    path.pb(i);
    for (int nb : adj[i]) if (nb != p && cycle(nb, i)) return true;
    path.pop_back();
    vis[i]=false;
    return false;
}

int dfs(int i, int p) {
    int ans = 1;
    trav(nb, adj[i]) if (nb != p && !vis[nb]) ans += dfs(nb, i);
    return ans;
}

void solve() {
    cin >> n;
    adj.clear(); adj.rsz(n);
    F0R(i, n) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    cyc.clear(); path.clear(); vis.rsz(n); fill(all(vis), false);
    cycle(0, 0);
    ll ans = (ll)n * (n-1);
    fill(all(vis), false);
    trav(i, cyc) vis[i]=true;
    trav(i, cyc) {
        ll cnt = dfs(i, i);
        ans -= cnt * (cnt-1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}