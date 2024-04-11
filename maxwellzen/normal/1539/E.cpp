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

int n, m;
vi k;
vector<array<pi, 2>> rgs;

void solve() {
    cin >> n >> m;
    k.rsz(n+1); rgs.rsz(n+1);
    FOR(i, 1, n+1) {
        cin >> k[i];
        cin >> rgs[i][0].F >> rgs[i][0].S >> rgs[i][1].F >> rgs[i][1].S;
    }
    multiset<int> s[2];
    array<vvi, 2> add, rem;
    F0R(i, 2) add[i].rsz(n+1), rem[i].rsz(n+1);
    k[0] = 0; s[0].insert(0);
    FOR(i, 1, n+1) {
        F0R(pos, 2) {
            if (! btw(k[i], rgs[i][pos].F, rgs[i][pos].S)) {
                for (int x : s[pos]) rem[pos][i].pb(x);
            } else {
                for (auto it = s[pos].begin(); it != s[pos].end() && *it < rgs[i][1-pos].F; it++) {
                    rem[pos][i].pb(*it);
                }
                for (auto it = s[pos].end(); it != s[pos].begin() && *next(it, -1) > rgs[i][1-pos].S; it--) {
                    rem[pos][i].pb(*next(it, -1));
                }
                if (!s[1-pos].empty() && btw(k[i-1], rgs[i][1-pos].F, rgs[i][1-pos].S)) {
                    add[pos][i].pb(k[i-1]);
                }
            }
        }
        F0R(pos, 2) {
            for (int x : rem[pos][i]) s[pos].erase(s[pos].find(x));
            for (int x : add[pos][i]) s[pos].insert(x);
        }
        debug(i, s[0], s[1]);
    }
    if (s[0].empty() && s[1].empty()) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int p, val;
    vi ans(n);
    if (s[0].empty()) val=*s[1].begin(), p=1;
    else p=0, val=*s[0].begin();
    ROF(i, 1, n+1) {
        F0R(pos, 2) {
            for (int x : add[pos][i]) s[pos].erase(s[pos].find(x));
            for (int x : rem[pos][i]) s[pos].insert(x);
        }
        debug(i, p, val, s[0], s[1]);
        ans[i-1] = p;
        if (val==k[i-1] && !s[1-p].empty()) {
            p = 1-p;
            val = *s[p].begin();
        }
    }
    FOR(i, 0, n) cout << ans[i] << ' ';
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