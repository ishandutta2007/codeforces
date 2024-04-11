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
vector<ll> bit; // resize to n+1 before starting
ll sum(int k) { // sum up to and including k
    ll s = 0;
    for (k++; k>0; k -= k&-k) s += bit[k];
    return s;
}
void add (int k, ll x) {for (k++; k<bit.size(); k += k&-k) bit[k] += x;}

int n, m;
vi a, b, c, p, tmp;
vpi ord;

void calc(int x, int y, int l, int r) {
    if (x>=y) return;
    int mid = (x+y)/2;
    int cur = 0;
    FOR(i, l, r+1) {
        tmp[i] += cur;
        if (i<n && a[i]>b[mid]) cur++;
    }
    cur = 0;
    ROF(i, l, r+1) {
        if (i<n && a[i]<b[mid]) cur++;
        tmp[i] += cur;
    }
    p[mid]=l;
    FOR(i, l, r+1) if (tmp[i]<tmp[p[mid]]) p[mid]=i;
    FOR(i, l, r+1) tmp[i]=0;
    calc(x, mid, l, p[mid]);
    calc(mid+1, y, p[mid], r);
}

void solve() {
    cin >> n >> m;
    read(a, n); read(b, m); sort(all(b));
    p.rsz(m);
    tmp.assign(n+1, 0);
    calc(0, m, 0, n);
    c.clear(); int cur = 0;
    F0R(i, n) {
        while (cur<m && p[cur]==i) c.pb(b[cur++]);
        c.pb(a[i]);
    }
    while (cur<m) c.pb(b[cur++]);
    ord.clear();
    F0R(i, n+m) ord.pb(mp(c[i], i));
    sort(all(ord));
    bit.assign(n+m+1, 0);
    ll ans = 0;
    for (pi x : ord) {
        ans += sum(n+m-1) - sum(x.S);
        add(x.S, 1);
    }
    debug(c);
    cout << ans << nl;
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