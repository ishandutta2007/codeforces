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

int n, m, u, v, tim, ldep;
vi st, ed, dep, sz, cnt;
vpi bad;
vvi adj, up;

void dfs(int i, int parent, int d) {
    up[i][0]=parent;
    st[i]=tim++;
    dep[i] = d;
    sz[i] = 1;
    for (int nb : adj[i]) if (nb!=parent) {
        dfs(nb, i, d+1);
        sz[i] += sz[nb];
    }
    ed[i]=tim-1;
}
void init(int root) {
    ldep=tim=0;
    while (pow(2, ldep) <= n) ldep++; ldep++;
    st.rsz(n), ed.rsz(n); up.rsz(n, vi(ldep)); dep.rsz(n); sz.rsz(n);
    dfs(root, root, 0);
    FOR(i, 1, up[0].size()) F0R(j, n) up[j][i] = up[up[j][i-1]][i-1];
}
int goup(int i, int k) { F0R(d, ldep) if (k&1<<d) i=up[i][d]; return i; }
bool anc(int i, int j) {return st[i]<=st[j] && ed[i]>=ed[j];}

void solve() {
    cin >> n >> m;
    adj.rsz(n);
    DSU d(n);
    F0R(i, m) {
        cin >> u >> v; u--; v--;
        if (d.same_set(u, v)) {
            bad.pb(mp(u, v));
        } else {
            d.unite(u, v);
            adj[u].pb(v); adj[v].pb(u);
        }
    }
    cnt.assign(n+1, 0);
    init(0);
    for (pi p : bad) {
        u = p.F, v = p.S;
        if (anc(v, u)) swap(u, v);
        if (anc(u, v)) {
            cnt[st[v]]++;
            cnt[st[v]+sz[v]]--;
            cnt[0]++;
            v = goup(v, dep[v]-dep[u]-1);
            cnt[st[v]]--;
            cnt[st[v]+sz[v]]++;
        } else {
            cnt[st[v]]++;
            cnt[st[v]+sz[v]]--;
            cnt[st[u]]++;
            cnt[st[u]+sz[u]]--;
        }
    }
    FOR(i, 1, n+1) cnt[i] += cnt[i-1];
    F0R(i, n) {
        if (cnt[st[i]] == m-n+1) cout << 1;
        else cout << 0;
    }
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