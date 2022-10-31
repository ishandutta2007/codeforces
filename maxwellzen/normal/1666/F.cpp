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
const ll MOD = 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name != "") {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

vll fact(2, 1), ifact(2, 1), invs(2, 1);
int nxt_uncalculated = 2;
void factinit(int n, ll m=MOD) {
    if (nxt_uncalculated>n) return;
    fact.rsz(n+1); ifact.rsz(n+1); invs.rsz(n+1);
    FOR(i, nxt_uncalculated, n+1) fact[i]=fact[i-1]*i%m, invs[i]=invs[m%i]*(m-m/i)%m, ifact[i]=ifact[i-1]*invs[i]%m;
    nxt_uncalculated = n+1;
}
ll choose(ll n, ll k, ll m=MOD) {
    if (k<0 || k>n) return 0;
    factinit(n, m);
    ll ans = (fact[n]*ifact[k])%m;
    ans = (ans*ifact[n-k])%m;
    return ans;
}

int n, m, h, cnt;
vi a, freq, pref;
vvll dp;

void solve() {
    cin >> n;
    h = n/2;
    read(a, n);
    freq.clear();
    F0R(i, n) {
        cnt++;
        if (i==n-1 || a[i] != a[i+1]) {
            freq.pb(cnt);
            cnt = 0;
        }
    }
    m = freq.size();
    reverse(all(freq));
    pref.rsz(m+1, 0);
    F0R(i, m) pref[i+1] = pref[i]+freq[i];
    if (m<h) {
        cout << 0 << nl;
        return;
    }
    dp.assign(m+1, vll(h+1, 0));
    dp[0][0] = 1;
    F0R(i, m) F0R(j, h+1) if (j<=i) {
        int num = pref[i];
        int spaces = max(j-1, 0) + (j==h);
        spaces = max(0, spaces-(num-j));
        if (j<h) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * choose(spaces, freq[i]-1))%MOD;
        dp[i+1][j] = (dp[i+1][j] + dp[i][j] * choose(spaces, freq[i]))%MOD;
    }
    cout << dp[m][h] << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}