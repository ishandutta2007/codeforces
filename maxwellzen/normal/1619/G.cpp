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

int n, k, numcmp;
vi x, y, timer, order, cmp, mintime;
vvi adj;
vb vis;

bool xcmp(int i, int j) { return x[i] < x[j] || (x[i]==x[j] && y[i]<y[j]); }
bool ycmp(int i, int j) { return y[i] < y[j] || (y[i]==y[j] && x[i]<x[j]); }
void fill(int i, int c) {
    if (vis[i]) return;
    vis[i] = true;
    cmp[i] = c;
    for (int nb : adj[i]) fill(nb, c);
}

void solve() {
    cin >> n >> k;
    x.rsz(n); y.rsz(n); timer.rsz(n);
    F0R(i, n) cin >> x[i] >> y[i] >> timer[i];
    order.rsz(n); F0R(i, n) order[i]=i;
    adj.clear(); adj.rsz(n);
    sort(all(order), xcmp);
    F0R(i, n-1) {
        int a=order[i], b=order[i+1];
        if (x[a]==x[b] && y[b] - y[a] <= k) {
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }
    sort(all(order), ycmp);
    F0R(i, n-1) {
        int a=order[i], b=order[i+1];
        if (y[a]==y[b] && x[b] - x[a] <= k) {
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }
    vis.assign(n, false);
    cmp.rsz(n);
    numcmp = 0;
    F0R(i, n) if (!vis[i]) fill(i, numcmp++);
    mintime.assign(numcmp, 1e9);
    F0R(i, n) ckmin(mintime[cmp[i]], timer[i]);
    debug(cmp, mintime);
    sort(all(mintime));
    reverse(all(mintime));
    F0R(i, numcmp-1) if (mintime[i+1] <= i) {
        cout << i << nl;
        return;
    }
    cout << numcmp-1 << nl;
    return;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}