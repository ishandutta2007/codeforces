#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
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

int n, m, k, u, v;
vector<unordered_set<int>> adj;
vb in;
vi cnt;
set<pi> s;

void rem(int i) {
    s.erase(mp(cnt[i], i));
    in[i]=false;
    for (int nb : adj[i]) {
        if (!in[nb]) continue;
        s.erase(mp(cnt[nb], nb));
        cnt[nb]--;
        adj[nb].erase(i);
        s.insert(mp(cnt[nb], nb));
    }
}

void solve() {
    cin >> n >> m >> k;
    adj.clear(); adj.rsz(n); in.clear(); in.rsz(n, false); cnt.clear(); cnt.rsz(n, 0);
    F0R(i, m) {
        cin >> u >> v, u--, v--;
        adj[u].insert(v); adj[v].insert(u);
    }
    if (k>500) {
        cout << -1 << nl;
        return;
    }
    F0R(i, n) {
        if (adj[i].size()>=k-1) {
            in[i]=true;
            for (int nb : adj[i]) cnt[nb]++;
        } else {
            for (int nb : adj[i]) adj[nb].erase(i);
        }
    }
    s.clear();
    F0R(i, n) if (in[i]) s.insert(mp(cnt[i], i));
    debug(s);
    while (s.size()>0 && s.begin()->F < k) {
        u = s.begin()->S;
        if (cnt[u]==k-1) {
            bool clique = true;
            for (int i : adj[u]) {
                if (!in[i]) continue;
                for (int j : adj[u]) {
                    if (!in[j]) continue;
                    if (i==j) continue;
                    if (adj[i].count(j)==0) {
                        clique=false;
                        break;
                    }
                }
                if (!clique) break;
            }
            if (clique) {
                cout << 2 << nl;
                cout << u+1 << ' ';
                for (int i : adj[u]) if (in[i]) cout << i+1 << ' ';
                cout << nl;
                return;
            }
        }
        rem(u);
    }
    if (s.size()>0) {
        cout << 1 << ' ' << s.size() << nl;
        for (pi p : s) cout << p.S+1 << ' ';
        cout << nl;
        return;
    }
    cout << -1 << nl;
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