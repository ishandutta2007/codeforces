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

vector<int> primes, factor;

void sieve2(int n) {
    factor.clear(); factor.resize(n+1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (factor[i]==0) {
            primes.push_back(i);
            for (int j = i; j <= n; j += i) factor[j]=i;
        }
    }
}

int n, q, zero, one;
ll w;
vi a, tosort;
map<int, int> freq, freq2;

void solve() {
    cin >> n;
    read(a, n);
    freq.clear(); freq2.clear();
    F0R(j, n) {
        int copy = a[j], i=a[j];
        while (i>1) {
            if (copy%(factor[i]*factor[i])==0) copy /= (factor[i]*factor[i]);
            i /= factor[i];
        }
        // cout << copy << ' ';
        freq[copy]++;
    }
    // cout << nl;
    tosort.clear();
    for (pi p : freq) {
        // cout << p.F << ' ' << p.S << nl;
        if (p.F==0 || p.S%2==0) freq2[1] += p.S; else freq2[p.F] += p.S;
        tosort.pb(p.S);
    }
    sort(all(tosort));
    zero = tosort[tosort.size()-1];
    tosort.clear();
    for (pi p : freq2) tosort.pb(p.S);
    sort(all(tosort));
    one = tosort[tosort.size()-1];
    cin >> q;
    F0R(i, q) {
        cin >> w;
        if (w==0) cout << zero << nl;
        else cout << one << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve2(1000000);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}