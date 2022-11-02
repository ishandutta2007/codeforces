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

int n;
vi ans, block;

int query(int a, int b, int c) {
    cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
    int ans; cin >> ans; return ans;
}

pi getpair(int b0, int b1) {
    if (query(b0, b0+1, b1)==1) return mp(b0+2, b1);
    if (query(b0+2, b1+1, b1+2)==0) return mp(b0+2, b1);
    if (query(b0, b1, b1+1)==0) return mp(b0, b1+2);
    return mp(b0+1, b1+1);
}

void solve() {
    cin >> n;
    ans.rsz(n); block.rsz(n/3);
    F0R(i, n/3) block[i] = query(3*i, 3*i+1, 3*i+2);
    int b0=-1, b1=-1;
    F0R(i, n/3) {
        if (block[i]==0) b0 = 3*i;
        else b1 = 3*i;
    }
    pi p = getpair(b0, b1);
    ans[p.F]=0; ans[p.S]=1;
    F0R(i, 3) {
        if (b0+i != p.F) ans[b0+i] = query(b0+i, p.F, p.S);
        if (b1+i != p.S) ans[b1+i] = query(b1+i, p.F, p.S);
    }
    F0R(i, n/3) {
        int b = 3*i;
        if (b==b0 || b==b1) continue;
        if (block[i]==0) {
            if (query(b, b+1, p.S)==0) {
                ans[b]=0, ans[b+1]=0;
                ans[b+2] = query(b+2, p.F, p.S);
            } else {
                ans[b+2] = 0;
                ans[b] = query(b, p.F, p.S);
                ans[b+1] = 1 - ans[b];
            }
        } else {
            if (query(b, b+1, p.F)==1) {
                ans[b]=1, ans[b+1]=1;
                ans[b+2] = query(b+2, p.F, p.S);
            } else {
                ans[b+2] = 1;
                ans[b] = query(b, p.F, p.S);
                ans[b+1] = 1 - ans[b];
            }
        }
    }
    vi v;
    F0R(i, n) if (ans[i]==0) v.pb(i);
    cout << "! " << v.size() << ' ';
    for (int i : v) cout << i+1 << ' ';
    cout << endl;
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