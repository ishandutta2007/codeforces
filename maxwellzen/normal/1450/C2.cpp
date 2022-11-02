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

int n;
vs grid;
vvb wall;

void flip(int r, int b) {
    char c = (b==1)?'O':'X';
    FOR(i, max(0, r-n+1), min(n, r+1)) {
        if (grid[i][r-i] != '.') grid[i][r-i]=c;
    }
}

void solve() {
    cin >> n;
    read(grid, n);
    wall.assign(n, vb(n, false));
    int k = 0;
    F0R(i, n) F0R(j, n) if (grid[i][j]!='.') k++;
    vvi diag(3, vi(2, 0));
    F0R(i, n) F0R(j, n) {
        if (grid[i][j]=='O') diag[(i+j)%3][0]++;
        else if (grid[i][j]=='X') diag[(i+j)%3][1]++;
    }
    F0R(i, 3) F0R(j, 3) {
        if (i!=j && diag[i][0]+diag[j][1] <= k/3) {
            F0R(a, n) F0R(b, n) {
                if ((a+b)%3==i && grid[a][b]!='.') grid[a][b]='X';
                else if ((a+b)%3==j && grid[a][b]!='.') grid[a][b]='O'; 
            }
            F0R(i, n) cout << grid[i] << nl;
            return;
        }
    }
    // debug(diag);
    // int dp[2*n-1][2][2], par[2*n-2][2][2];
    // fill(*dp[0], *dp[2*n-1], 1e9);
    // F0R(i, 2) F0R(j, 2) dp[i][j][1] = diag[0][i]+diag[1][j];
    // FOR(i, 2, 2*n-1) {
    //     F0R(a, 2) F0R(b, 2) F0R(c, 2) if (a!=b || b!=c) {
    //         if (ckmin(dp[i][b][c], dp[i-1][a][b]+diag[i][c])) par[i][b][c]=a;
    //     }
    // }
    // int a=0, b=0, i=2*n-2;
    // F0R(i, 2) F0R(j, 2) if (dp[2*n-2][i][j]<dp[2*n-2][a][b]) a=i, b=j;
    // flip(i, b); flip(i-1, a);
    // while (i>1) {
    //     int temp = a;
    //     a = par[i][a][b]; b = temp;
    //     flip(i-2, a);
    //     i--;
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}