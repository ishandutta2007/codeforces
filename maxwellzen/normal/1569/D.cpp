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

int n, m, k;
vi x, y;
vpi onx, ony;
vvi byx, byy;
vi xind, yind;

bool cmpy(pi a, pi b) {
    return a.S < b.S;
}

void solve() {
    cin >> n >> m >> k;
    read(x, n); read(y, m);
    byx.clear(); byx.rsz(n); byy.clear(); byy.rsz(m);
    onx.clear(); ony.clear();
    pi cur;
    F0R(i, k) {
        cin >> cur.F >> cur.S;
        bool a=false, b=false;
        if (binary_search(all(x), cur.F)) a=true;
        if (binary_search(all(y), cur.S)) b=true;
        if (a&&b) continue;
        else if (a) {
            onx.pb(cur);
            int j = lb(all(x), cur.F)-x.begin();
            byx[j].pb(cur.S);
        } else if (b) {
            ony.pb(cur);
            int j = lb(all(y), cur.S)-y.begin();
            byy[j].pb(cur.F);
        }
    }
    F0R(i, n) sort(all(byx[i]));
    F0R(i, m) sort(all(byy[i]));
    xind.assign(n, 0); yind.assign(m, 0);
    ll ans = 0;
    sort(all(onx), cmpy);
    sort(all(ony));
    F0R(i, onx.size()) {
        cur = onx[i];
        int cy = *lb(all(y), cur.S);
        int j = lb(all(x), cur.F)-x.begin();
        int k = lb(all(onx), mp(0, cy), cmpy)-onx.begin();
        ans += k-i-1;
        k = lb(all(byx[j]), cy)-byx[j].begin();
        ans -= k-xind[j]-1;
        xind[j]++;
    }
    F0R(i, ony.size()) {
        cur = ony[i];
        int cx = *lb(all(x), cur.F);
        int j = lb(all(y), cur.S)-y.begin();
        int k = lb(all(ony), mp(cx, 0))-ony.begin();
        ans += k-i-1;
        k = lb(all(byy[j]), cx)-byy[j].begin();
        ans -= k-yind[j]-1;
        yind[j]++;
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}