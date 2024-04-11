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
const ll MOD = 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name != "") {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

map<int, int> mn;

struct number {
    map<int, int> p;
    number(int x) {
        for (int i = 2; i*i <= x; i++) {
            while (x%i==0) {
                x /= i; p[i]++;
            }
        }
        if (x>1) p[x]++;
    }
    number& operator*=(number b) {
        for (pi c : b.p) p[c.F] += c.S;
        return *this;
    }
    number& operator/=(number b) {
        for (pi c : b.p) {
            p[c.F] -= c.S;
            mn[c.F] = min(mn[c.F], p[c.F]);
        }
        return *this;
    }
};
ll mod_exp(ll a, ll b, ll m=MOD) {
    ll r = 1;
    for( ; b ; b /= 2, a = (a*a)%m) if (b&1) r = (r*a)%m;
    return r;
}
ll inv(ll a, ll m=MOD) { return mod_exp(a, m-2, m); }

int n, i, j, x, y;
vector<vector<ai<3>>> adj;
number val = number(1);

void dfs(int i, int p) {
    for (ai<3> nb : adj[i]) if (nb[0] != p) {
        number a(nb[1]), b(nb[2]);
        val *= a; val /= b;
        dfs(nb[0], i);
        val *= b; val /= a;
    }
}
ll getsum(int i, int p, ll a) {
    ll ans = a;
    for (ai<3> nb : adj[i]) if (nb[0] != p) {
        ans += getsum(nb[0], i, a * nb[1] % MOD * inv(nb[2]) % MOD);
        ans %= MOD;
    }
    return ans;
}

void solve() {
    cin >> n;
    adj.clear(); adj.rsz(n); mn.clear();
    F0R(edge, n-1) {
        cin >> i >> j >> x >> y; i--; j--;
        adj[i].pb({j, y, x});
        adj[j].pb({i, x, y});
    }
    val = number(1);
    dfs(0, -1);
    ll factor = 1;
    for (pi c : mn) {
        factor = factor * mod_exp(c.F, -c.S) % MOD;
    }
    cout << getsum(0, -1, 1) * factor % MOD << nl;
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