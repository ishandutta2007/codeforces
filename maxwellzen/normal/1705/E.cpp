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

const int ID = 0;
const ll SZ = 2e5+50;
int sum[4*SZ], lazy[4*SZ];
void init() { for (int i = 0; i < 4*SZ; i++) sum[i]=0, lazy[i]=-1; }
int combine(int A, int B) { return A+B; }
int combineUpd(int A, int B) { return B; }
void push(int index, ll L, ll R) {
    if (lazy[index] != -1) {
        sum[index] = (R-L+1)*lazy[index];
        if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
        lazy[index] = -1;
    }
}
void pull(int index) { sum[index] = combine(sum[2*index], sum[2*index+1]); }
int query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return ID;
    if (lo <= L && R <= hi) return sum[index];
    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}
void update(int lo, int hi, int increase, int index = 1, ll L = 0, ll R = SZ-1) {
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
int one_after(int x, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (sum[index]==0) return -1;
    if (L==R) return L;
    int M = (L+R)/2;
    if (M<x) return one_after(x, 2*index+1, M+1, R);
    if (L<x) {
        int res = one_after(x, 2*index, L, M);
        if (res != -1) return res;
        return one_after(x, 2*index+1, M+1, R);
    }
    push(2*index, L, M);
    if (sum[2*index] == 0) return one_after(x, 2*index+1, M+1, R);
    return one_after(x, 2*index, L, M);
}
int zero_after(int x, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (sum[index]==R-L+1) return -1;
    if (L==R) return L;
    int M = (L+R)/2;
    if (M<x) return zero_after(x, 2*index+1, M+1, R);
    if (L<x) {
        int res = zero_after(x, 2*index, L, M);
        if (res != -1) return res;
        return zero_after(x, 2*index+1, M+1, R);
    }
    push(2*index, L, M);
    if (sum[2*index] == M-L+1) return zero_after(x, 2*index+1, M+1, R);
    return zero_after(x, 2*index, L, M);
}
void subtract(int x) {
    if (query(x, x) == 1) update(x, x, 0);
    else {
        int y = one_after(x);
        update(y, y, 0);
        update(x, y-1, 1);
    }
}
void add(int x) {
    if (query(x, x) == 0) update(x, x, 1);
    else {
        int y = zero_after(x);
        update(y, y, 1);
        update(x, y-1, 0);
    }
}
int highest(int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (sum[index]==0) return -1;
    if (L==R) return L;
    int M = (L+R)/2;
    push(2*index+1, M+1, R);
    if (sum[2*index+1] == 0) return highest(2*index, L, M);
    return highest(2*index+1, M+1, R);
}

int n, q, k, l;
vi a;
vi cnt;

void solve() {
    cin >> n >> q;
    read(a, n);
    cnt.assign(SZ, 0);
    for (int i : a) cnt[i]++;
    F0R(i, SZ-1) if (cnt[i]>1) {
        cnt[i+1] += cnt[i]/2;
        cnt[i] = cnt[i]%2;
    }
    F0R(i, SZ) if (cnt[i]==1) update(i, i, 1);
    F0R(query, q) {
        cin >> k >> l; k--;
        subtract(a[k]);
        a[k] = l;
        add(a[k]);
        cout << highest() << nl;
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