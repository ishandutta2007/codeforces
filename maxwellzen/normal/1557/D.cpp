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
#define debug(x) cout<<#x<<" = "<<x<<nl
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}

const pi identity = mp(0, -1);
const ll SZ = 1e6+10;
pi sum[4*SZ], lazy[4*SZ];
void init() { for (int i = 0; i < 4*SZ; i++) sum[i]=lazy[i]=identity; }
pi combine(pi A, pi B) { return max(A, B); }
pi combineUpd(pi A, pi B) { return max(A, B); }
void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}
void pull(int index) { sum[index] = combine(sum[2*index], sum[2*index+1]); }
pi query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sum[index];
    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}
void update(int lo, int hi, pi increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }
    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int n, m, a, l, r;
vvpi segs;
set<int> coords;
vi compress, pre;

void solve() {
    cin >> n >> m;
    segs.rsz(n);
    F0R(i, m) {
        cin >> a >> l >> r, a--;
        segs[a].pb(mp(l, r));
        coords.insert(l); coords.insert(r);
    }
    for (int i : coords) compress.pb(i);
    F0R(i, n) {
        F0R(j, (int)segs[i].size()) {
            segs[i][j].F = (int)(lower_bound(all(compress), segs[i][j].F)-compress.begin());
            segs[i][j].S = (int)(lower_bound(all(compress), segs[i][j].S)-compress.begin());
        }
    }
    pre.rsz(n);
    init();
    F0R(i, n) {
        // cout << i << endl;
        pi mx = {0,-1};
        for (pi p : segs[i]) mx=max(mx, query(p.F, p.S));
        // cout << mx.F << ' ' << mx.S << endl;
        pre[i]=mx.S;
        for (pi p : segs[i]) update(p.F, p.S, mp(mx.F+1, i));
        // cout << "updated" << endl;
    }
    pi mx = query(0, 2*m);
    cout << n - mx.F << nl;
    set<int> keep;
    int i = mx.S;
    while (i != -1) {
        keep.insert(i);
        i=pre[i];
    }
    F0R(i, n) if (keep.find(i)==keep.end()) cout << i+1 << ' ';
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}