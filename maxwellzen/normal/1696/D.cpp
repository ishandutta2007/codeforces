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
vi a, b;

struct Seg { // comb(ID,b) = b
    bool ismax;
    int n; vector<int> seg; vi v;
    int ID = 1e9;
    int comb(int a, int b) { 
        if (a==ID) return b;
        if (b==ID) return a;
        if (ismax == (v[a]>v[b])) return a;
        return b; }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void init(int _n, vi& V, bool b) {
        n = _n; v = V; ismax = b; seg.rsz(2*n);
        FOR(i, n, 2*n) seg[i] = i-n;
        ROF(i, 1, n) pull(i); }
    void upd(int p, int val) { // set val at position p
        v[p] = val; p += n; for (p /= 2; p; p /= 2) pull(p); }
    int query(int l, int r) {  // min on interval [l, r]
        int ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

Seg maxa, mina, minb;

void solve() {
    cin >> n;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    F0R(i, n) a[i]--;
    b.rsz(n);
    F0R(i, n) b[a[i]] = i;
    maxa.init(n, a, true);
    mina.init(n, a, false);
    minb.init(n, b, false);
    int cur = 0, ans = 0;
    while (cur < n-1) {
        int lim, up=-1, down=-1, nxt;
        if (mina.query(cur, n-1) == cur) {
            nxt = maxa.query(cur, n-1);
        } else if (maxa.query(cur, n-1) == cur) {
            nxt = mina.query(cur, n-1);
        } else {
            up = b[minb.query(a[cur]+1, n-1)];
            down = b[minb.query(0, a[cur]-1)];
            // debug(cur, up, down);
            if (up > down) nxt = mina.query(cur, up-1);
            else nxt = maxa.query(cur, down-1);
        }
        FOR(i, cur, nxt) minb.upd(a[i], 1e9);
        cur = nxt;
        // debug(cur);
        ans++;
    }
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