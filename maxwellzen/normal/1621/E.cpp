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
vi a, k, loc, x, y, z;
vvi b;
vector<array<ll, 3>> ord;
vll sum;

bool cmp(array<ll, 3> a, array<ll, 3> b) {
    return (a[0]*b[1] < b[0]*a[1]);
}

void solve() {
    cin >> n >> m;
    read(a, n);
    sort(all(a));
    reverse(all(a));
    k.rsz(m); b.clear(); b.rsz(m); ord.clear(); sum.rsz(m);
    F0R(i, m) {
        cin >> k[i];
        read(b[i], k[i]);
        sum[i]=0; F0R(j, k[i]) sum[i] += b[i][j];
        ord.pb({sum[i], ll(k[i]), ll(i)});
    }
    sort(all(ord), cmp);
    reverse(all(ord));
    debug(b);
    debug(ord);
    debug(a);
    loc.rsz(m);
    F0R(i, m) loc[ord[i][2]] = i;
    x.assign(m+1, 0); y.assign(m+1, 0); z.assign(m+1, 0);
    FOR(i, 1, m) if (ord[i][0] <= ord[i][1]*a[i-1]) x[i+1]=1;
    F0R(i, m) if (ord[i][0] <= ord[i][1]*a[i]) y[i+1]=1;
    F0R(i, m-1) if (ord[i][0] <= ord[i][1]*a[i+1]) z[i+1]=1;
    F0R(i, m) x[i+1] += x[i], y[i+1] += y[i], z[i+1] += z[i];
    debug(x, y, z);

    F0R(i, m) {
        F0R(j, k[i]) {
            ll sum2 = sum[i] - b[i][j];
            int from = loc[i];
            int l=0, r=m-2, to=m-1;
            while (l <= r) {
                int mid = (l+r)/2;
                int nxt = mid;
                if (nxt>=from) nxt++;
                if (sum2*ord[nxt][1] >= ord[nxt][0] * (k[i]-1)) {
                    to = mid;
                    r = mid-1;
                } else l=mid+1;
            }
            // debug(b[i][j], from, to);
            if (to<=from) {
                if (y[to] + z[from]-z[to] + y[m]-y[from+1] == m-1 && sum2 <= (ll)a[to]*(k[i]-1)) cout << 1;
                else cout << 0;
            } else {
                if (y[from] + x[to+1]-x[from+1] + y[m]-y[to+1] == m-1 && sum2 <= (ll)a[to]*(k[i]-1)) cout << 1;
                else cout << 0;
            }
        }
    }
    cout << nl;
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