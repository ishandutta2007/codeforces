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

template<class T> using pql = priority_queue<T>;
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

int n, u, v, ans;
ll s, sum[2];
vvpi adj;
vi w, c, cnt;
pql<pl> pq[2];
vll seq[2];

int dfs(int i, int p) {
    if (i != 0 && adj[i].size()==1) {
        cnt[adj[i][0].S]=1;
        return 1;
    }
    int ans = 0;
    for (pi nb : adj[i]) if (nb.F != p) ans += dfs(nb.F, i);
    for (pi nb : adj[i]) if (nb.F==p) cnt[nb.S]=ans;
    return ans;
}

ll diff(int i) {
    return (ll)cnt[i] * ((w[i]+1)/2);
}

void solve() {
    cin >> n >> s;
    adj.clear(); adj.rsz(n); w.rsz(n-1); c.rsz(n-1); cnt.rsz(n-1);
    F0R(i, n-1) {
        cin >> u >> v >> w[i] >> c[i];
        u--; v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    dfs(0, 0);
    sum[0] = sum[1] = 0;
    ans = 0;
    F0R(i, 2) while (!pq[i].empty()) pq[i].pop();
    F0R(i, n-1) {
        sum[c[i]-1] += (ll)cnt[i]*w[i];
        pq[c[i]-1].push({diff(i), i});
    }
    F0R(i, 2) {
        seq[i].clear(); seq[i].pb(sum[i]);
        while (!pq[i].empty()) {
            pl cur = pq[i].top();
            pq[i].pop();
            sum[i] -= cur.F;
            w[cur.S] /= 2;
            seq[i].pb(sum[i]);
            if (w[cur.S]>0) pq[i].push({diff(cur.S), cur.S});
        }
    }
    int j = seq[1].size()-1;
    ans = 1e9;
    F0R(i, seq[0].size()) {
        while (j>0 && seq[0][i]+seq[1][j-1]<=s) j--;
        if (seq[0][i]+seq[1][j]<=s) ans=min(ans, i+2*j);
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}