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
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

int n, u, v;
vvi adj;
vector<pair<pi, pi>> dp;
vi val;

pi better(pi a, pi b) {
    if (a.F > b.F) return a;
    if (a.F < b.F) return b;
    if (a.S < b.S) return a;
    return b;
}
void dfs(int i, int p) {
    dp[i] = mp(mp(1, adj[i].size()), mp(0, 1));
    for (int nb : adj[i]) if (nb != p) {
        dfs(nb, i);
        dp[i].F = dp[i].F + dp[nb].S;
        dp[i].S = dp[i].S + better(dp[nb].F, dp[nb].S);
    }
}
pi construct(int i, int p, bool b1, bool b2) {
    if (!b1) {
        if (better(dp[i].F, dp[i].S)==dp[i].F) b2=true;
        else b2=false;
    }
    pi ans;
    if (b2) {
        val[i] = adj[i].size();
        ans = mp(1, adj[i].size());
        for (int nb : adj[i]) if (nb != p) ans = ans + construct(nb, i, true, false);
    } else {
        val[i] = 1;
        ans = mp(0, 1);
        for (int nb : adj[i]) if (nb != p) ans = ans + construct(nb, i, false, false);
    }
    return ans;
}

void solve() {
    cin >> n;
    adj.rsz(n);
    F0R(i, n-1) {
        cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    if (n==2) {
        cout << "2 2\n1 1\n";
        return;
    }
    dp.rsz(n);
    dfs(0, -1);
    val.rsz(n);
    pi ans = construct(0, -1, false, false);
    cout << ans.F << ' ' << ans.S << nl;
    F0R(i, n) cout << val[i] << ' ';
    cout << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}