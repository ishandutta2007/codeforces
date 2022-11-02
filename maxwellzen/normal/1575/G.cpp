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

vector<int> primes, factor;

void sieve2(int n) {
    factor.clear(); factor.resize(n+1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (factor[i]==0) {
            primes.push_back(i);
            factor[i] = i;
        }
        int lim = min(factor[i], n/i);
        for (int j = 0; j < primes.size() && primes[j] <= lim; j++)
            factor[i*primes[j]] = primes[j];
    }
}

int N = 100000;
int n;
vi a, phi, cnt, rem;
vvi plist, dlist;

void init() {
    sieve2(N);
    phi.rsz(N+1); plist.rsz(N+1); dlist.rsz(N+1);
    FOR(i, 1, N+1) {
        int x = i;
        dlist[i].pb(1);
        phi[i] = i;
        while (x>1) {
            int p = factor[x], e = 0;
            while (x%p==0) x /= p, e++;
            plist[i].pb(p);
            phi[i] /= p; phi[i] *= p-1;
            int sz = dlist[i].size(), mult = 1;
            F0R(rep, e) {
                mult *= p;
                F0R(j, sz) dlist[i].pb(dlist[i][j] * mult);
            }
        }
    }
}

void solve() {
    init();
    cin >> n;
    a.rsz(n+1);
    F0R(i, n) cin >> a[i+1];
    cnt.assign(N+1, 0);
    ll ans = 0;
    FOR(x, 1, n+1) {
        ll cur = 0;
        for (int i = x; i <= n; i += x) {
            for (int d : dlist[a[i]]) {
                if (cnt[d]==0) rem.pb(d);
                cnt[d]++;
            }
        }
        for (int d : rem) {
            cur += ll(cnt[d])*cnt[d]*phi[d] % MOD;
            cnt[d] = 0;
        }
        rem.clear();
        cur %= MOD;
        cur = (cur * phi[x])%MOD;
        ans = (ans+cur)%MOD;
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