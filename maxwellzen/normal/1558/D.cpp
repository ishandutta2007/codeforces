#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> iset;

#pragma GCC optimize ("O3")

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
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

vector<ll> bit; // resize to n+1 before starting
ll sum(int k) { // sum up to and including k
    ll s = 0;
    for (k++; k>0; k -= k&-k) s += bit[k];
    return s;
}
void add (int k, ll x) {for (k++; k<bit.size(); k += k&-k) bit[k] += x;}

const int N = 400000;
int n, m, x, y;
vpi pairs;
set<int> one;
vi restore;
ll fact[N], ifact[N];


ll mod_exp(ll a, ll b, ll m) {
    ll r = 1;
    for( ; b ; b /= 2, a = (a*a)%m) if (b&1) r = (r*a)%m;
    return r;
}
ll inv(ll a, ll m=MOD) { return mod_exp(a, m-2, m); }
ll choose(int n, int m) {
    ll ans = (fact[n] * ifact[m])%MOD;
    ans = (ans * ifact[n-m])%MOD;
    return ans;
}

int index(int i) {
    int l=i, r=n-1, ans=n;
    while (l <= r) {
        int mid = (l+r)/2;
        if (sum(mid) >= i+1) {
            ans = mid;
            r = mid-1;
        } else l=mid+1;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    pairs.rsz(m);
    one.clear();
    restore.clear();
    F0R(i, m) cin >> pairs[i].F >> pairs[i].S;
    R0F(i, pairs.size()) {
        y = index(pairs[i].S-1);
        int y2 = index(pairs[i].S);
        one.insert(y2);
        add(y, -1);
        restore.pb(y);
    }
    cout << choose(2*n-1-one.size(), n) << nl;
    for (int i : restore) add(i, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0]=1;
    FOR(i, 1, N) fact[i]=(fact[i-1]*i)%MOD;
    F0R(i, N) ifact[i]=inv(fact[i]);
    bit.rsz(200001);
    F0R(i, 200001) add(i, 1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}