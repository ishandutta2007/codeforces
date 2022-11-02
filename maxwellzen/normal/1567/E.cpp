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

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return a+b; }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {  // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

ll n, q, t, x, y;
vll a;
set<ll> start;
Seg<ll> st;

void update(ll i) {
    if (start.find(i)==start.end()) {
        st.upd(i, 0);
    } else {
        ll j = *start.upper_bound(i);
        st.upd(i, (ll)(j-i)*(j-i+1)/2);
    }
}

void solve() {
    cin >> n >> q;
    read(a, n);
    start.insert(n);
    start.insert(0);
    FOR(i, 1, n) if (a[i]<a[i-1]) start.insert(i);
    st.init(n);
    F0R(i, n) update(i);
    F0R(i, q) {
        cin >> t >> x >> y;
        if (t==1) {
            x--;
            a[x] = y;
            if (x!=n-1) {
                if (a[x+1]<y) start.insert(x+1);
                else start.erase(x+1);
                update(x+1);
            }
            if (x==0 || a[x]<a[x-1]) start.insert(x);
            else start.erase(x);
            update(x); 
            if (x!=0) update(*--start.lower_bound(x));
            // F0R(j, n) cout << st.query(j, j) << ' ';
            // cout << nl;
        } else {
            x--; y--;
            ll l = *start.lower_bound(x), r = *--start.upper_bound(y);
            debug(start, x, y, l, r);
            ll ans = 0;
            if (l<=r) {
                if (l<r) ans += st.query(l, r-1);
                ans += (l-x)*(l-x+1)/2;
                ans += (y-r+1)*(y-r+2)/2;
            } else {
                ans += (y-x+1)*(y-x+2)/2;
            }
            cout << ans << nl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}