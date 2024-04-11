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
#include "C:/Users/maxwe/CP/debug.cpp"
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

struct pt {
    ll x,y;
    pt() {x = y = 0;}
    pt(ll X, ll Y) {x=X, y=Y;}
    pt operator-(pt b) {return pt(x-b.x, y-b.y);}
    pt operator+(pt b) {return pt(x+b.x, y+b.y);}
    ll above(pt a, pt b) {
        a = a - *this;
        b = b - *this;
        ll cross = a.y*b.x - b.y*a.x;
        return cross;
    }
};

int n, h;
vector<pt> pts;

void solve() {
    cin >> n >> h;
    pts.rsz(n);
    F0R(i, n) cin >> pts[i].x >> pts[i].y;
    pt eye = pts[n-1] + pt(0,h);
    pt peak = pts[n-1];
    db ans = 0;
    R0F(i, n-1) {
        if (eye.above(pts[i+1], peak)<0) peak = pts[i+1];
        debug(peak.x, peak.y);
        if (eye.above(pts[i+1],peak)==0 && eye.above(pts[i],peak)==0) {
            debug(i);
            db x=pts[i+1].x-pts[i].x, y=pts[i+1].y-pts[i].y;
            ans += sqrt(x*x+y*y);
        } else if (eye.above(pts[i], peak)<0) {
            debug(i);
            ll a1=peak.y-eye.y, b1=eye.x-peak.x, c1=eye.x*peak.y - peak.x*eye.y;
            ll a2=pts[i].y-pts[i+1].y, b2=pts[i+1].x-pts[i].x, c2=pts[i+1].x*pts[i].y - pts[i].x*pts[i+1].y;
            db x = db(b2*c1-b1*c2) / (b2*a1-b1*a2);
            db y = db(a2*c1-a1*c2) / (a2*b1-a1*b2);
            ans += sqrt((x-pts[i].x)*(x-pts[i].x) + (y-pts[i].y)*(y-pts[i].y));
        }
    }
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