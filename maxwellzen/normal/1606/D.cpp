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

int n, m;
vvi a;
vvpi pre, suf;

void solve() {
    cin >> n >> m;
    a.assign(n, vi(m));
    F0R(i, n) F0R(j, m) cin >> a[i][j];
    pre.assign(n, vpi(m));
    suf.assign(n, vpi(m));
    F0R(i, n) {
        pre[i][0] = mp(a[i][0], a[i][0]);
        FOR(j, 1, m) pre[i][j] = mp(min(a[i][j], pre[i][j-1].F), max(a[i][j], pre[i][j-1].S));
    }
    F0R(i, n) {
        suf[i][m-1] = mp(a[i][m-1], a[i][m-1]);
        R0F(j, m-1) suf[i][j] = mp(min(a[i][j], suf[i][j+1].F), max(a[i][j], suf[i][j+1].S));
    }
    F0R(col, m-1) {
        vpi ord1, ord2;
        F0R(i, n) {
            ord1.pb(mp(pre[i][col].F, i));
            ord1.pb(mp(pre[i][col].S, i));
            ord2.pb(mp(suf[i][col+1].F, i));
            ord2.pb(mp(suf[i][col+1].S, i));
        }
        sort(all(ord1));
        sort(all(ord2));
        reverse(all(ord2));
        vi cnt(n, 0);
        int bad = 0;
        F0R(i, 2*n-1) {
            if (cnt[ord1[i].S]==0) bad++;
            if (cnt[ord1[i].S]==3) bad--;
            cnt[ord1[i].S]++;
            if (cnt[ord2[i].S]==0) bad++;
            if (cnt[ord2[i].S]==3) bad--;
            cnt[ord2[i].S]++;
            if (bad==0 && ord1[i].F<ord1[i+1].F && ord2[i].F>ord2[i+1].F) {
                YES;
                F0R(row, n) cout << (cnt[row]==4 ? 'B' : 'R');
                cout << ' ' << col+1 << nl;
                return;
            }
        }
    }
    NO;
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