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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}

ll n;
vll fact, two, ifact;
ll dp[402][402];

ll mod_exp(ll a, ll b, ll m = MOD) {
    ll r = 1;
    for( ; b ; b /= 2, a = (a*a)%m) if (b&1) r = (r*a)%m;
    return r;
}
array<ll, 3> euclid(ll a, ll b) {
    if (a == 0) return {b, 0, 1};
    array<ll, 3> res = euclid(b%a, a);
    return {res[0], res[2] - (b/a) * res[1], res[1]};
}
ll inv(ll a, ll m = MOD) { return ((euclid(a, m)[1]%m)+m)%m; }

ll choose(ll n, ll m) {
    ll ans = fact[n];
    ans = (ans * ifact[m])%MOD;
    ans = (ans * ifact[n-m])%MOD;
    return ans;
}

void solve() {
    cin >> n >> MOD;
    fact.rsz(n+1);
    two.rsz(n+1);
    ifact.rsz(n+1);
    fact[0]=1; two[0]=1;
    FOR(i, 1, n+1) fact[i]=(fact[i-1]*i)%MOD;
    F0R(i, n+1) ifact[i]=inv(fact[i]);
    FOR(i, 1, n+1) two[i]=(two[i-1]*2)%MOD;
    dp[0][0]=1;
    FOR(i, 0, n+1) {
        FOR(j, 0, i+1) {
            if (dp[i][j]==0) continue;
            FOR(k, 2, n+2-i) {
                ll add = (two[k-2] * choose(j+k-1, k-1))%MOD;
                add = (add * dp[i][j])%MOD;
                dp[i+k][j+k-1] = (dp[i+k][j+k-1]+add)%MOD;
            }
        }
    }
    // print(dp, n+2, n+2);
    ll ans = 0;
    F0R(i, n+2) ans = (ans+dp[n+1][i])%MOD;
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    
    while (t--) {
        solve();
    }
}