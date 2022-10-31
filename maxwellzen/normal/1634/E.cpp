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

int n;
vi k;
vvi a;
vvb ans, vis;
vector<vvpi> adj;
map<int, vpi> locs;

void dfs(int i, int j, bool b) {
    if (vis[i][j]) return;
    vis[i][j] = true;
    ans[i][j] = b;
    for (pi nb : adj[i][j]) if (!vis[nb.F][nb.S]) dfs(nb.F, nb.S, !b);
}

void solve() {
    cin >> n;
    k.rsz(n); a.rsz(n); ans.rsz(n); vis.rsz(n); adj.rsz(n);
    F0R(i, n) {
        cin >> k[i];
        a[i].rsz(k[i]); ans[i].rsz(k[i], false); vis[i].rsz(k[i], false); adj[i].rsz(k[i]);
        map<int, int> loc;
        F0R(j, k[i]) {
            cin >> a[i][j];
            if (loc.find(a[i][j]) != loc.end()) {
                vis[i][loc[a[i][j]]] = true;
                ans[i][loc[a[i][j]]] = false;
                vis[i][j] = true;
                ans[i][j] = true;
                loc.erase(a[i][j]);
            } else loc[a[i][j]] = j;
        }
        for (pi p : loc) locs[p.F].pb(mp(i, p.S));
        int cur = -1;
        F0R(j, k[i]) if (!vis[i][j]) {
            if (cur==-1) cur=j;
            else {
                adj[i][cur].pb(mp(i, j));
                adj[i][j].pb(mp(i, cur));
                cur = -1;
            }
        }
    }
    for (auto &p : locs) {
        if (p.S.size()%2 != 0) {
            NO; return;
        }
        for (int i = 0; i < p.S.size(); i += 2) {
            pi a = p.S[i], b = p.S[i+1];
            adj[a.F][a.S].pb(b);
            adj[b.F][b.S].pb(a);
        }
    }
    F0R(i, n) F0R(j, k[i]) if (!vis[i][j]) dfs(i, j, false);
    YES;
    F0R(i, n) {
        F0R(j, k[i]) cout << (ans[i][j] ? 'L' : 'R');
        cout << nl;
    }
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}