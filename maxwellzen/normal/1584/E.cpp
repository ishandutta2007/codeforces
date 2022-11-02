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
template<int N> using al = array<ll, N>;
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

struct Seg { // comb(ID,b) = b
    const al<4> ID = {0, 0, (ll)1e18, (ll)1e18};
    al<4> comb(al<4> a, al<4> b) {
        al<4> ans;
        ans[0] = a[0]+b[0];
        if (b[0]%2==0) ans[1] = b[1]+a[1];
        else ans[1] = b[1]-a[1];
        if (a[0]%2==0) {
            ans[2] = min(a[2], b[2]-a[1]);
            ans[3] = min(a[3], b[3]+a[1]);
        } else {
            ans[2] = min(a[2], b[3]+a[1]);
            ans[3] = min(a[3], b[2]-a[1]);
        }
        return ans;
    }
    int n; vector<al<4>> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, ll val) { // set val at position p
        seg[p += n] = {1, val, val, (ll)1e18}; for (p /= 2; p; p /= 2) pull(p); }
    al<4> query(int l, int r) {  // min on interval [l, r]
        al<4> ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int n;
vi a;
vll p;
Seg st1;
map<ll, vi> loc;

void solve() {
    cin >> n;
    read(a, n);
    st1.init(n); F0R(i, n) st1.upd(i, a[i]);
    p.assign(n+1, 0);
    F0R(i, n) {
        if (i%2==0) p[i+1]=p[i]+a[i];
        else p[i+1]=p[i]-a[i];
    }
    loc.clear();
    F0R(i, n+1) loc[p[i]].pb(i);
    ll cnt = 0;
    F0R(i, n) {
        int l = i+1, r = n-1, ans = i;
        while (l <= r) {
            int m = (l+r)/2;
            al<4> res = st1.query(i, m);
            if (min(res[2], res[3]) >= 0) {
                ans = m;
                l = m+1;
            } else r = m-1;
        }
        cnt += upper_bound(all(loc[p[i]]), ans+1) - upper_bound(all(loc[p[i]]), i);
    }
    cout << cnt << nl;
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