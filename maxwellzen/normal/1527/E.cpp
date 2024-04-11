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

const int N=35000, K=100;
const int identity = 0;
const ll SZ = 35000;
int sum[4*SZ][K], lazy[4*SZ][K];
void init() { for (int i = 0; i < 4*SZ; i++) F0R(j, K) sum[i][j]=lazy[i][j]=identity; }
int combine(int A, int B) { return min(A, B); }
int combineUpd(int A, int B) { return A+B; }
void push(int index, int j, ll L, ll R) {
    sum[index][j] = combineUpd(sum[index][j], lazy[index][j]);
    if (L != R) lazy[2*index][j] = combineUpd(lazy[2*index][j], lazy[index][j]), lazy[2*index+1][j] = combineUpd(lazy[2*index+1][j], lazy[index][j]);
    lazy[index][j] = identity;
}
void pull(int index, int j) { sum[index][j] = combine(sum[2*index][j], sum[2*index+1][j]); }
int query(int lo, int hi, int j, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, j, L, R);
    if (lo > R || L > hi) return INT_MAX;
    if (lo <= L && R <= hi) return sum[index][j];
    int M = (L+R) / 2;
    return combine(query(lo, hi, j, 2*index, L, M), query(lo, hi, j, 2*index+1, M+1, R));
}
void update(int lo, int hi, int increase, int j, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, j, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index][j] = increase;
        push(index, j, L, R);
        return;
    }
    int M = (L+R) / 2;
    update(lo, hi, increase, j, 2*index, L, M); update(lo, hi, increase, j, 2*index+1, M+1, R);
    pull(index, j);
}


int n, k;
vi a;
vi loc;

void solve() {
    cin >> n >> k;
    read(a, n);
    loc.assign(n+1, -1);
    init();
    int cur = 0;
    F0R(i, n) {
        if (loc[a[i]]>-1) {
            cur += i - loc[a[i]];
        }
        loc[a[i]] = i;
        debug(i, cur);
        update(i, i, cur, 0);
    }
    loc.assign(n+1, -1);
    F0R(i, n) {
        if (loc[a[i]]>-1) {
            F0R(j, k-1) {
                update(0, loc[a[i]]-1, i-loc[a[i]], j);
            }
        }
        loc[a[i]] = i;
        FOR(j, 1, k) {
            int x = query(0, i, j-1);
            update(i, i, x, j);
        }
    }
    cout << query(n-1, n-1, k-1) << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    while (t--) {
        solve();
    }
}