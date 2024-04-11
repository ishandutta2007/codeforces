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

const db PI = 3.1415926535897932384626;
db sq(db x) {return x*x;}
struct point {
    db x, y, mag, ang;
    point(int X, int Y) {
        x = X, y = Y;
        mag = sqrt(sq(x) + sq(y));
        ang = atan2(y, x);
    }
    pd range(db r) {
        db cur = acos(mag / (2*r));
        pd ans = mp(ang-cur, ang+cur);
        if (ans.F < -PI) ans.F += 2*PI;
        if (ans.S > PI) ans.S -= 2*PI;
        return ans;
    }
};

int n, k, x, y;
vector<point> pts;

void solve() {
    cin >> n >> k;
    int tmp = 0;
    F0R(i, n) {
        cin >> x >> y;
        if (x==0 && y==0) tmp++;
        else pts.pb(point(x, y));
    }
    if (tmp>=k) {
        cout << 0 << nl;
        return;
    }
    n -= tmp; k -= tmp;
    db l = 0, r = 200000, ans = 200000;
    while (r-l >= 0.00001) {
        db m = (l+r)/2;
        vector<pd> ranges;
        F0R(i, n) if (pts[i].mag <= 2*m) ranges.pb(pts[i].range(m));
        // debug(m, ranges);
        vector<db> vals;
        for (pd p : ranges) {
            vals.pb(p.F);
            vals.pb(p.S);
        }
        sort(all(vals));
        vi cnt(2*n+1, 0);
        for (pd p : ranges) {
            int a = lower_bound(all(vals), p.F) - vals.begin();
            int b = lower_bound(all(vals), p.S) - vals.begin();
            cnt[a]++;
            cnt[b+1]--;
            if (a>b) cnt[0]++;
        }
        F0R(i, 2*n) cnt[i+1] += cnt[i];
        bool works = false;
        F0R(i, 2*n) if (cnt[i]>=k) works = true;
        if (works) {
            ans = m;
            r = m;
        } else l = m;
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