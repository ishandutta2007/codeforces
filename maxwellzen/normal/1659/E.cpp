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

int n, m, q, a, b;
vector<ai<3>> edges;
vb haseven;
vvi zerocmp, onecmp;
vvb onegood;

void solve() {
    cin >> n >> m;
    edges.rsz(m);
    haseven.assign(n, false);
    for (ai<3> &edge : edges) {
        cin >> edge[0] >> edge[1] >> edge[2];
        edge[0]--; edge[1]--;
        if (edge[2]%2==0) haseven[edge[0]]=haseven[edge[1]]=true;
    }
    zerocmp.rsz(30, vi(n));
    F0R(bit, 30) {
        DSU d(n);
        for (ai<3> edge : edges) if (edge[2] & 1<<bit) d.unite(edge[0], edge[1]);
        F0R(i, n) zerocmp[bit][i] = d.get(i);
    }
    onecmp.rsz(30, vi(n));
    onegood.assign(30, vb(n, false));
    FOR(bit, 1, 30) {
        DSU d(n);
        F0R(i, m) if (edges[i][2]&1) if (edges[i][2] & 1<<bit) d.unite(edges[i][0], edges[i][1]);
        F0R(i, n) {
            int cmp = d.get(i);
            onecmp[bit][i] = cmp;
            if (haseven[i]) onegood[bit][cmp]=true;
        }
    }
    cin >> q;
    F0R(query, q) {
        cin >> a >> b; a--; b--;
        bool zero=false, one=false;
        F0R(bit, 30) if (zerocmp[bit][a]==zerocmp[bit][b]) zero=true;
        if (zero) cout << 0 << nl;
        else {
            FOR(bit, 1, 30) if (onegood[bit][onecmp[bit][a]]) {
                one=true;
            }
            if (one) cout << 1 << nl;
            else cout << 2 << nl;
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