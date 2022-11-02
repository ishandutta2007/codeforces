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
vs hold;
vvb grid;
vpi one, zero, seq;

void flip(pi a) {
    seq.pb(a);
    grid[a.F][a.S] = !grid[a.F][a.S];
}
void flip(int x, int y) {
    flip(mp(x, y));
}
void flip(pi a, pi b, pi c) {
    flip(a); flip(b); flip(c);
}
void prt(pi a, pi b, pi c) {
    cout << a.F+1 << ' ' << a.S+1 << ' ' << b.F+1 << ' ' << b.S+1 << ' ' << c.F +1 << ' ' << c.S+1 << nl;
}

void moveright(int x, int y) {
    int cnt = 0;
    if (grid[x][y]) {cnt++; flip(x, y);}
    if (grid[x+1][y]) {cnt++; flip(x+1, y);}
    if (cnt%3 != 0) {cnt++; flip(x, y+1);}
    if (cnt%3 != 0) {cnt++; flip(x+1, y+1);}
    ans += cnt/3;
}

void movedown(int x, int y) {
    int cnt = 0;
    if (grid[x][y]) {cnt++; flip(x, y);}
    if (grid[x][y+1]) {cnt++; flip(x, y+1);}
    if (cnt%3 != 0) {cnt++; flip(x+1, y);}
    if (cnt%3 != 0) {cnt++; flip(x+1, y+1);}
    ans += cnt/3;
}


void calc() {
    if (one.size()==0) return;
    if (one.size()==1) {
        ans += 3;
        flip(one[0], zero[0], zero[1]);
        flip(one[0], zero[2], zero[0]);
        flip(one[0], zero[1], zero[2]);
    }
    if (one.size()==2) {
        ans += 2;
        flip(one[0], zero[0], zero[1]);
        flip(one[1], zero[0], zero[1]);
    }
    if (one.size()==3) {
        ans++;
        flip(one[0], one[1], one[2]);
    }
    if (one.size()==4) {
        ans += 4;
        flip(one[1], one[2], one[3]);
        flip(one[0], one[1], one[2]);
        flip(one[0], one[1], one[3]);
        flip(one[0], one[2], one[3]);
    } 
}

void printgrid() {
    F0R(i, n) {
        F0R(j, m) cout << (grid[i][j]?'1':'0');
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> n >> m;
    hold.clear(); read(hold, n);
    grid.clear(); grid.rsz(n, vb(m));
    F0R(i, n) F0R(j, m) grid[i][j]=(hold[i][j]=='1');
    seq.clear();
    ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (i==n-1) i--;
        F0R(j, m-2) {
            moveright(i, j);
            // printgrid();
        }
    }
    F0R(i, n-2) {
        movedown(i, m-2);
        // printgrid();
    }
    one.clear(); zero.clear();
    FOR(i, n-2, n) FOR(j, m-2, m) {
        if (grid[i][j]) one.pb(mp(i, j));
        else zero.pb(mp(i, j));
    }
    // debug(one, zero);
    calc();
    cout << seq.size()/3 << nl;
    for (int i = 0; i < (int)seq.size()-2; i += 3) {
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