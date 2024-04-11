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

struct mi {
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mi() { v = 0; }
    mi(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
    friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
    mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
    mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD; return *this; }
    mi& operator*=(const mi& m) { v = int((ll)v*m.v%MOD); return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator^ (mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a.v != 0); return a ^ (MOD-2); }
        
    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream &operator<<(ostream &output, const mi& a) { return (output << a.v); }
    friend istream &operator>>(istream &input, mi &a) { ll k; input >> k; a = mi(k); return input; }
};
typedef vector<mi> vm;
typedef vector<vm> vvm;
str to_string(mi a) {return to_string(a.v);}

int n, twon;
vi a;
vvm x;

void solve() {
    cin >> n;
    read(a, n);
    x.assign(n, vm(n));
    F0R(i, n) F0R(j, n) if (i != j) x[i][j] = mi(a[i]) / mi(a[i]+a[j]);
    twon = 1<<n;
    mi dp[n][twon];
    F0R(i, n) dp[i][1<<i]=1;
    vector<pair<int, mi>> beat[twon];
    FOR(sub, 1, twon) {
        int rest = (twon-1) ^ sub;
        for (int sub2 = rest; sub2 > 0; sub2 = (sub2-1)&rest) beat[sub].pb(mp(sub2, 0));
        beat[sub].pb(mp(0, 1)); sort(all(beat[sub]));
        for (auto p : beat[sub]) if (p.F!=0) {
            int sub2 = p.F;
            int i = __builtin_ctz(sub2);
            mi cur = lb(all(beat[sub]), mp(sub2^1<<i, mi(0)))->S;
            for (int k = sub; k>0; k -= k&-k) cur *= x[__builtin_ctz(k)][i];
            lb(all(beat[sub]), mp(sub2, mi(0)))->S = cur;
        }
    }
    F0R(sub, twon) if (__builtin_popcount(sub)>1) {
        F0R(i, n) if (sub & 1<<i) {
            dp[i][sub] = 1;
            int rest = sub ^ 1<<i;
            for (int sub2 = rest; sub2 > 0; sub2 = (sub2-1)&rest) {
                int sub3 = sub ^ sub2;
                mi cur = dp[i][sub3];
                cur *= lb(all(beat[sub2]), mp(sub3, mi(0)))->S;
                dp[i][sub] -= cur;
            }
        }
    }
    mi ans = 0;
    F0R(i, n) ans += dp[i][twon-1];
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