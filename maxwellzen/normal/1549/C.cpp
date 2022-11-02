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

int t, n, m, q, u, v, type;
int cnt[200010] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int ans = n;
    F0R(i, m) {
        cin >> u >> v;
        ckmin(u, v);
        if (cnt[u]++==0) ans--;
    }
    cin >> q;
    F0R(query, q) {
        cin >> type;
        if (type==3) cout << ans << '\n';
        else {
            cin >> u >> v; 
            ckmin(u, v);
            if (type==1) {if (cnt[u]++==0) ans--;}
            else if (type==2) {if (cnt[u]--==1) ans++;}
        }
    }
}