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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void read(vi& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
void read(vvi& a, int n, int m) {a.rsz(n, vi(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}

const int N = 2e5+10;
int lazy[N * 4], seg[N * 4];

int t, n, q;
str s, f;
vi a, l, r;

void shift(int id, int l, int r)
{
    if(lazy[id] == -1) return;
    int mid = (l + r) >> 1;
    lazy[id << 1] = lazy[id];
    lazy[id << 1 | 1] = lazy[id];
    seg[id << 1] = (mid - l + 1) * lazy[id];
    seg[id << 1 | 1] = (r - mid) * lazy[id];
    lazy[id] = -1;
}
 
void upd(int x, int y, int val, int l=0, int r=n-1, int id=1)
{
    if(l >= x && r <= y)
    {
        seg[id] = val * (r - l + 1);
        lazy[id] = val;
        return;
    }
    if(l > y || r < x)
        return ;
    int mid = (l + r) >> 1;
    shift(id, l, r);
    upd(x, y, val, l, mid, id << 1);
    upd(x, y, val, mid + 1, r, id << 1 | 1);
    seg[id] = seg[id << 1] + seg[id << 1 | 1]; 
}
 
int query(int x, int y, int l=0, int r=n-1, int id=1)
{
    if(l >= x && r <= y)
        return seg[id];
    if(l > y || r < x)
        return 0;
    shift(id, l, r);
    int mid = (l + r) >> 1;
    return query(x, y, l, mid, id << 1) + query(x, y, mid + 1, r, id << 1 | 1);
 
}

void solve() {
    cin >> n >> q >> s >> f;
    memset(lazy, -1, n * 4 * sizeof lazy[0]);
    a.rsz(n);
    F0R(i, n) upd(i, i, f[i]-'0');
    l.rsz(q); r.rsz(q);
    F0R(i, q) cin >> l[i] >> r[i];
    R0F(i, q) {
        // F0R(i, n) cout << query(i, i);
        // cout << '\n';
        int sq = query(l[i]-1, r[i]-1), len = r[i]-l[i]+1;
        // cout << l[i] << ' ' << r[i] << ' ' << sq << '\n';
        if (sq*2<len) {
            upd(l[i]-1, r[i]-1, 0);
        } else if ((len-sq)*2 < len) {
            upd(l[i]-1, r[i]-1, 1);
        } else {
            cout << "NO\n";
            return;
        }
    }
    F0R(i, n) {
        if (s[i] != query(i, i)+'0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}