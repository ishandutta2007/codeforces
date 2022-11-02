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

const int N = 100001;
int n, m1, m2;
map<int, int> v[N];
set<int> row[N], col[N];
set<pi> rows;

void merger(int a, int b) {
    for (int i : row[b]) {
        row[a].insert(i);
        v[a][i] = v[b][i];
        col[i].erase(b);
        col[i].insert(a);
    }
}
void mergec(int a, int b) {
    for (int i : col[b]) {
        col[a].insert(i);
        v[i][a] = v[i][b];
        row[i].erase(b);
        row[i].insert(a);
    }
}

void solve() {
    cin >> n >> m1 >> m2;
    DSU d1(n), d2(n);
    F0R(i, m1) {
        int u, v;
        cin >> u >> v; u--; v--;
        d1.unite(u, v);
    }
    F0R(i, m2) {
        int u, v;
        cin >> u >> v; u--; v--;
        d2.unite(u, v);
    }
    if (m1 < m2) swap(d1, d2), swap(m1, m2);
    cout << n - 1 - m1 << nl;
    F0R(i, n) {
        int r = d1.get(i), c = d2.get(i);
        v[r][c] = i+1;
        row[r].insert(c);
        col[c].insert(r);
    }
    F0R(i, n) if (d1.get(i)==i) rows.insert(mp(row[i].size(), i));

    while (rows.size()>1) {
        int r1 = rows.rbegin()->S; rows.erase(*rows.rbegin());
        int r2 = rows.rbegin()->S; rows.erase(*rows.rbegin());
        int c1 = *row[r1].begin(), c2 = *row[r2].begin();
        if (c1==c2) c1 = *next(row[r1].begin());
        cout << v[r1][c1] << ' ' << v[r2][c2] << nl;
        merger(r1, r2);
        if (col[c1].size()<col[c2].size()) swap(c1, c2);
        mergec(c1, c2);
        rows.insert(mp(row[r1].size(), r1));
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