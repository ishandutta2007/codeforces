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

int N = 200005, q, d, a;
int cnt[1<<19], lazy[1<<19];
ll ans, seg[1<<19];
vb is;

void push(int node, int L, int R) {
    seg[node] += (ll)lazy[node]*cnt[node];
    if (L != R) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
    lazy[node] = 0;
}
void setval(int i, int x, int node = 1, int L = 1, int R = N) {
    push(node, L, R);
    cnt[node] += x;
    if (L==R) return;
    int M = (L+R)/2;
    if (i<=M) setval(i, x, 2*node, L, M);
    else setval(i, x, 2*node+1, M+1, R);
}
void setsum(int i, ll x, int node = 1, int L = 1, int R = N) {
    push(node, L, R);
    if (L==R) {
        seg[node] = x;
        return;
    }
    int M = (L+R)/2;
    if (i<=M) {
        setsum(i, x, 2*node, L, M);
        push(2*node+1, M+1, R);
    } else {
        push(2*node, L, M);
        setsum(i, x, 2*node+1, M+1, R);
    }
    seg[node] = seg[2*node] + seg[2*node+1];
}
void add(int l, int r, int x, int node = 1, int L = 1, int R = N) {
    push(node, L, R);
    if (l>R || L>r) return;
    if (l <= L && R <= r) {
        lazy[node] += x;
        push(node, L, R);
        return;
    }
    int M = (L+R)/2;
    add(l, r, x, 2*node, L, M);
    add(l, r, x, 2*node+1, M+1, R);
    seg[node] = seg[2*node] + seg[2*node+1];
}
int getcnt(int l, int r, int node = 1, int L = 1, int R = N) {
    if (l>R || L>r) return 0;
    if (l <= L && R <= r) return cnt[node];
    int M = (L+R)/2;
    return getcnt(l, r, 2*node, L, M) + getcnt(l, r, 2*node+1, M+1, R);
}
ll getsum(int l, int r, int node = 1, int L = 1, int R = N) {
    if (l>R || L>r) return 0;
    push(node, L, R);
    if (l <= L && R <= r) return seg[node];
    int M = (L+R)/2;
    return getsum(l, r, 2*node, L, M) + getsum(l, r, 2*node+1, M+1, R);
}

void solve() {
    cin >> q >> d;
    is.assign(N, false);
    while (q--) {
        cin >> a;
        if (is[a]) {
            int left = getcnt(a-d, a-1), right = getcnt(a+1, a+d);
            ans -= (ll)left*(left-1)/2;
            ans -= (ll)right*(right-1)/2;
            ans -= getsum(a-d, a-1) - (ll)left*getcnt(1, a);
            is[a] = false;
            setval(a, -1);
            add(a-d, N, -1);
            setsum(a, 0);
        } else {
            is[a] = true;
            setval(a, 1);
            add(a-d, N, 1);
            setsum(a, getcnt(1, a+d));
            int left = getcnt(a-d, a-1), right = getcnt(a+1, a+d);
            ans += (ll)left*(left-1)/2;
            ans += (ll)right*(right-1)/2;
            ans += getsum(a-d, a-1) - (ll)left*getcnt(1, a);
        }
        cout << ans << nl;
    }
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}