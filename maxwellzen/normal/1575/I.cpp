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

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return a+b; }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        p += n; seg[p] += val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {  // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int n, q, tim, ldep;
vi x, st, ed, cnt;
vvi adj, up;
Seg<ll> seg;

void dfs(int i, int parent) {
    up[i][0]=parent;
    st[i]=tim++;
    cnt[i] = 1;
    for (int nb : adj[i]) if (nb!=parent) {
        dfs(nb, i);
        cnt[i] += cnt[nb];
    }
    ed[i]=tim-1;
}
void init(int root) {
    ldep=tim=0;
    while (pow(2, ldep) <= n) ldep++; ldep++;
    st.rsz(n), ed.rsz(n); up.rsz(n, vi(ldep)); cnt.rsz(n);
    dfs(root, root);
    FOR(i, 1, up[0].size()) F0R(j, n) up[j][i] = up[up[j][i-1]][i-1];
}
int goup(int i, int k) { F0R(d, ldep) if (k&1<<d) i=up[i][d]; return i; }
bool anc(int i, int j) {return st[i]<=st[j] && ed[i]>=ed[j];}
int lca(int i, int j) {
    if (anc(i, j)) return i;
    R0F(d, ldep) if (! anc(up[i][d], j)) i=up[i][d];
    return up[i][0];
}

void solve() {
    cin >> n >> q;
    read(x, n); F0R(i, n) x[i] = abs(x[i]);
    adj.rsz(n);
    F0R(i, n-1) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    init(0);
    seg.init(n);
    F0R(i, n) {
        seg.upd(st[i], x[i]);
        if (st[i]+cnt[i]<n) seg.upd(st[i]+cnt[i], -x[i]);
    }
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t==1) {
            u--;
            v = abs(v);
            int val = v - x[u];
            x[u] = v;
            seg.upd(st[u], val);
            if (st[u]+cnt[u]<n) seg.upd(st[u]+cnt[u], -val);
        } else {
            if (u==v) cout << 0 << nl;
            else {
                u--; v--;
                int a = lca(u, v);
                ll res = 2*seg.query(0, st[u]) + 2*seg.query(0, st[v]) - 4*seg.query(0, st[a]);
                res += (ll)2*x[a] - x[u] - x[v];
                cout << res << nl;
            }
        }
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