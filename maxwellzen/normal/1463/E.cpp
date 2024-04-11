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

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

const int Mxn = 300005;
int n, k, x, y;
vi path, prereq;
vector<set<int>> adj;
bool t1[Mxn], t2[Mxn], vis[Mxn];
vi cmps[Mxn];

void dfs(int i) {
    if (vis[i]) return;
    vis[i]=true;
    for (int nb : adj[i]) dfs(nb);
    path.pb(i);
}

void solve() {
    cin >> n >> k;
    adj.rsz(n+1);
    prereq.rsz(n+1);
    FOR(i, 1, n+1) cin >> prereq[i];
    DSU d(n+1);
    F0R(i, k) {
        cin >> x >> y;
        if (t1[x] || t2[y] || d.same_set(x, y)) {
            cout << 0 << nl;
            return;
        }
        t1[x]=t2[y]=true;
        d.unite(x, y);
        adj[x].insert(y);
    }
    FOR(i, 1, n+1) dfs(i);
    reverse(all(path));
    for (int i : path) cmps[d.get(i)].pb(i);
    path.clear(); adj.clear(); adj.rsz(n+1);
    FOR(i, 1, n+1) {
        adj[0].insert(d.get(i));
        adj[d.get(prereq[i])].insert(d.get(i));
    }
    fill(vis, vis+n+1, false);
    dfs(0); path.pop_back(); reverse(all(path));
    vi ans;
    for (int i : path) {
        ans.insert(ans.end(), cmps[i].begin(), cmps[i].end());
    }
    fill(vis, vis+n+1, false);
    vis[0]=true;
    for (int i : ans) if (!vis[prereq[i]]) {
        cout << 0 << nl;
        return;
    } else vis[i]=true;
    print(ans, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}