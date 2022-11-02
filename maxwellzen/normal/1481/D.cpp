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
#define arr array
#define nl '\n'
#define debug(x) cout<<#x<<" = "<<x<<nl
#define print(x) cout<<x<<nl

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}

int n, m;
vs a;

void solve() {
    cin >> n >> m;
    read(a, n);
    if (m%2 != 0) {
        cout << "YES\n";
        F0R(i, m+1) cout << (i%2)+1 << ' ';
        cout << nl;
        return;
    }
    pi ans = mp(-1, -1);
    F0R(j, n) F0R(i, j) {
        if (a[i][j]==a[j][i]) ans=mp(i, j);
    }
    if (ans.F != -1) {
        cout << "YES\n";
        F0R(i, m+1) {
            if (i%2==0) cout << ans.F+1 << ' ';
            else cout << ans.S+1 << ' ';
        }
        cout << nl;
        return;
    }
    arr<int, 3> trip = {-1, -1, -1};
    F0R(i, n) {
        int f = (i==0 ? 1 : 0);
        F0R(j, n) if (j != i && a[i][j] != a[i][f]) {
            trip = {i, f, j};
            break;
        }
        if (trip[0]>-1) break;
    }
    if (trip[0]>-1) {
        array<int, 4> cycle;
        if (m%4==0) {
            cycle = {0,1,0,2};
        } else {
            cycle = {1,0,2,0};
        }
        cout << "YES\n";
        F0R(i, m+1) {
            cout << trip[cycle[i%4]]+1 << ' ';
        }
        cout << nl;
        return;
    }
    cout << "NO\n";
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