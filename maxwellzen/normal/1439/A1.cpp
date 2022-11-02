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
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.rsz(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

int n, m, ans;
vs grid;
vpi one, zero;
vpi seq;

void print(pi a) {
    seq.pb(a);
    grid[a.F][a.S] = '0' + '1' - grid[a.F][a.S];
}
void print(pi a, pi b, pi c) {
    print(a); print(b); print(c);
}
void prt(pi a, pi b, pi c) {
    cout << a.F+1 << ' ' << a.S+1 << ' ' << b.F+1 << ' ' << b.S+1 << ' ' << c.F +1 << ' ' << c.S+1 << nl;
}

void calc() {
    if (one.size()==0) return;
    if (one.size()%3==2) {
        ans += 2;
        print(one[0]); print(zero[0]); print(zero[1]);
        print(one[1]); print(zero[0]); print(zero[1]);
    } else if (one.size()%3==1) {
        if (one.size()==4) {
            ans++;
            print(one[1], one[2], one[3]);
            FOR(i, 1, 4) zero.pb(one[i]);
            one.rsz(1);
        }
        ans += 3;
        print(one[0]); print(zero[0]); print(zero[1]);
        print(one[0]); print(zero[2]); print(zero[0]);
        print(one[0]); print(zero[1]); print(zero[2]);
    } else {
        print(one[0], one[1], one[2]);
    }
}

void solve() {
    cin >> n >> m;
    read(grid, n);
    seq.clear();
    int ans = 0;
    F0R(i, n-1) F0R(j, m-1) {
        one.clear(); zero.clear();
        F0R(a, 2) F0R(b, 2) {
            if (grid[i+a][j+b]=='1') one.pb(mp(i+a, j+b));
            else zero.pb(mp(i+a, j+b));
        }
        calc();
    }
    cout << seq.size()/3 << nl;
    for (int i = 0; i < seq.size(); i += 3) {
        prt(seq[i], seq[i+1], seq[i+2]);
    }
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