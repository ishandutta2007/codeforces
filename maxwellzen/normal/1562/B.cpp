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
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

vector<int> primes;
vector<bool> isprime;

void sieve(int n) {
    isprime.clear(); isprime.resize(n+1, true); isprime[1]=false;
    primes.clear();
    for (int i = 2; i <= n; i ++) if (isprime[i]) {
        primes.push_back(i);
        if ((ll)i*i <= n) for (int j = i*i; j <= n; j += i) isprime[j]=false;
    }
}

int k;
str s;
vi digs;

void solve() {
    cin >> k >> s;
    digs.rsz(k);
    F0R(i, k) digs[i] = (s[i]-'0');
    // debug(digs);
    F0R(i, k) if (digs[i]>0 && !isprime[digs[i]]) {
        cout << 1 << nl << digs[i] << nl;
        return;
    }
    F0R(j, k) F0R(i, j) {
        if (10*digs[i]+digs[j]>0 && !isprime[10*digs[i]+digs[j]]) {
            cout << 2 << nl << digs[i] << digs[j] << nl;
            return;
        }
    }
    F0R(c, k) F0R(b, c) F0R(a, b) {
        if (100*digs[a]+10*digs[b]+digs[c]>0 && !isprime[100*digs[a]+10*digs[b]+digs[c]]) {
            cout << 3 << nl << digs[a] << digs[b] << digs[c] << nl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1001);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}