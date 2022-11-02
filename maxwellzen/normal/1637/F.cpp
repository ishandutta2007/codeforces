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
    const T ID = mp(0,-1); T comb(T a, T b) { return max(a,b); }
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

vector<ll> bit; // resize to n+1 before starting
ll sum(int k) { // sum up to and including k
    ll s = 0;
    for (; k>0; k -= k&-k) s += bit[k];
    return s;
}
void add (int k, ll x) {for (k++; k<bit.size(); k += k&-k) bit[k] += x;}

int n, u, v, tim;
vi h, st, ed, par;
vvi adj;
vpi ord;
Seg<pi> seg;

void dfs(int i, int p) {
    st[i] = tim++;
    par[i] = p;
    for (int nb : adj[i]) if (nb != p) dfs(nb, i);
    ed[i] = tim-1;
}

void solve() {
    cin >> n;
    read(h, n);
    adj.rsz(n);
    F0R(i, n-1) {
        cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    st.rsz(n); ed.rsz(n); par.rsz(n);
    dfs(0, 0);
    seg.init(n);
    F0R(i, n) if (adj[i].size()==1) {
        seg.upd(st[i], mp(h[i], i));
    }
    bit.assign(n+1, 0);
    F0R(i, n) {
        add(st[i], 1);
        ord.pb(mp(h[i], i));
    }
    sort(all(ord));
    for (pi p : ord) {
        int i = p.S, cnt = 0;
        if (adj[i].size()==1) cnt++;
        vpi possible;
        for (int nb : adj[i]) if (nb != par[i]) {
            if (sum(ed[nb]+1) == sum(st[nb])) {
                pi cur = seg.query(st[nb], ed[nb]);
                if (cur.F>=h[i]) cnt++;
                else if (cur.S != -1) possible.pb(cur);
            } else cnt++;
        }
        if (sum(st[i])==0 && sum(n)==sum(ed[i]+1)) {
            pi cur = max(seg.query(0, st[i]-1), seg.query(ed[i]+1, n-1));
            if (cur.F>=h[i]) cnt++;
            else if (cur.S != -1) possible.pb(cur);
        } else cnt++;
        sort(all(possible));
        while (cnt<2) {
            int j = possible.back().S;
            seg.upd(st[j], mp(h[i], j));
            possible.pop_back();
            cnt++;
        }
        add(st[i], -1);
    }
    ll ans = 0;
    F0R(i, n) if (adj[i].size()==1) ans += seg.query(st[i], st[i]).F;
    cout << ans << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}