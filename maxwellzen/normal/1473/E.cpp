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
typedef vector<vpi> vvpi;

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
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/maxwellzen/CP/debug.cpp"
#endif

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<int N> using ai = array<int, N>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.assign(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name != "") {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int n, m, u, v, w;
vvpi adj;
vvll dp;
vvb vis;

void solve() {
    cin >> n >> m;
    adj.rsz(n);
    F0R(i, m) {
        cin >> u >> v >> w; u--; v--;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    pqg<array<ll, 3>> pq;
    dp.assign(4, vll(n, 1e18));
    dp[0][0] = 0; pq.push({0, 0, 0});
    vis.assign(4, vb(n, false));
    while (! pq.empty()) {
        array<ll, 3> cur = pq.top();
        pq.pop();
        int i = cur[1], j = cur[2];
        if (vis[i][j]) continue;
        vis[i][j] = true;
        for (pi p : adj[j]) {
            if (dp[i][p.F] > dp[i][j] + p.S) {
                dp[i][p.F] = dp[i][j] + p.S;
                pq.push({dp[i][p.F], i, p.F});
            }
            if (i%2==0 && dp[i+1][p.F] > dp[i][j]) {
                dp[i+1][p.F] = dp[i][j];
                pq.push({dp[i+1][p.F], i+1, p.F});
            }
            if (i<2 && dp[i+2][p.F] > dp[i][j] + 2*p.S) {
                dp[i+2][p.F] = dp[i][j] + 2*p.S;
                pq.push({dp[i+2][p.F], i+2, p.F});
            }
        }
    }
    for (pi p : adj[0]) if (dp[3][p.F] > p.S) dp[3][p.F] = p.S;
    FOR(i, 1, n) cout << dp[3][i] << ' ';
    cout << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}