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

int n, m, q;
ll total;
vll a, b, c, p, ans;
vpi queries, edges;
vi st, cnt, dsu;

int get(int i) {
    if (dsu[i]==i) return i;
    return dsu[i] = get(dsu[i]);
}
void merge(int i, int j) {
    i = get(i); j = get(j);
    if (i==j) return;
    total -= p[st[i]+cnt[i]] - p[st[i]];
    total -= p[st[j]+cnt[j]] - p[st[j]];
    dsu[i] = j;
    st[j] = min(st[i], st[j]);
    cnt[j] += cnt[i];
    total += p[st[j]+cnt[j]] - p[st[j]];
}

void solve() {
    cin >> n >> m >> q;
    read(a, n);
    total = 0; for (int i : a) total += i;
    read(b, m);
    sort(all(a)); sort(all(b));
    c.clear(); c.insert(c.end(), all(a)); c.insert(c.end(), all(b));
    sort(all(c));
    reverse(all(a)); reverse(all(b)); reverse(all(c));
    F0R(i, n+m-1) edges.pb(mp(c[i]-c[i+1], i));
    sort(all(edges));
    p.assign(n+m+1, 0);
    F0R(i, n+m) p[i+1] = p[i]+c[i];

    st.rsz(n+m);
    F0R(i, n+m) st[i] = i;
    dsu.rsz(n+m); F0R(i, n+m) dsu[i] = i;
    cnt.assign(n+m, 0); int tmp = 0;
    F0R(i, n+m) if (c[i]==a[tmp]) cnt[i]=1, tmp++;

    queries.rsz(q);
    F0R(i, q) cin >> queries[i].F, queries[i].S=i;
    ans.rsz(q);
    sort(all(queries));
    int edge = 0;
    for (pi query : queries) {
        while (edge < n+m-1 && edges[edge].F <= query.F) {
            merge(edges[edge].S, edges[edge].S+1);
            edge++;
        }
        ans[query.S] = total;
    }
    F0R(i, q) cout << ans[i] << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}