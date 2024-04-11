#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> iset;

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
        for (int j = 0; j < primes.size() && primes[j] <= i && i*primes[j] <= n; j++)
            factor[i*primes[j]] = primes[j];
    }
}
// unordered_map<long long, int, chash> safe_map;
// gp_hash_table<long long, int, chash> safe_hash_table;
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(int x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int N = 20000000;
int n, cur, cnt;
vi a;
vpi factors, freq;
vvi flist, plist;
int divs[N+1];

void rec(int i) {
    if (i==factors.size()) {
        divs[cur] += cnt;
        flist.back().pb(cur);
        return;
    }
    int cp = cur;
    rec(i+1);
    F0R(j, factors[i].S) {
        cur *= factors[i].F;
        rec(i+1);
    }
    cur = cp;
}

void solve() {
    cin >> n;
    read(a, n);
    sort(all(a));
    cur = 0;
    F0R(i, n) {
        cur++;
        if (i==n-1 || a[i]!=a[i+1]) {
            freq.pb(mp(a[i], cur));
            cur = 0;
        }
    }
    for (pi p : freq) {
        int x = p.F;
        factors.clear();
        plist.pb(vi());
        while (x>1) {
            int base = factor[x], exp = 0;
            while (x%base==0) x /= base, exp++;
            factors.pb(mp(base, exp));
            plist.back().pb(base);
        }
        cur = 1, cnt = p.S;
        flist.pb(vi());
        rec(0);
    }
    ll ans = 0;
    gp_hash_table<int, ll, chash> dp;
    F0R(i, freq.size()) if (divs[freq[i].F] == freq[i].S) {
        dp.clear();
        dp[1]=n;
        for (int f : flist[i]) {
            for (int p : plist[i]) if (f%p==0) dp[f]=max(dp[f], dp[f/p]+ll(divs[f])*(f-f/p));
        }
        ans = max(ans, dp[freq[i].F]);
    }
    cout << ans << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    sieve2(N);
    while (t--) {
        solve();
    }
}