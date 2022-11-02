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

int n, m;
vvi dir, len, tim;
map<char, int> ctoi{{'D',0}, {'R',1}, {'U',2}, {'L',3}};
vvb vis;

int dfs(int i, int j) {
    int ni=i+dx[dir[i][j]], nj=j+dy[dir[i][j]];
    if (!btw(ni, 0, n-1) || !btw(nj, 0, m-1)) {
        vis[i][j]=true;
        len[i][j]=1;
        return -1;
    }
    if (vis[ni][nj]) {
        len[i][j] = len[ni][nj]+1;
        vis[i][j]=true;
        return -1;
    }
    if (tim[ni][nj]>-1) {
        len[i][j] = tim[i][j]-tim[ni][nj]+1;
        vis[i][j]=true;
        return tim[ni][nj];
    }
    tim[ni][nj] = tim[i][j]+1;
    int tmp = dfs(ni, nj);
    if (tmp==-1) len[i][j]=len[ni][nj]+1;
    else len[i][j]=len[ni][nj];
    vis[i][j]=true;
    if (tim[i][j]==tmp) return -1;
    else return tmp;
}

void solve() {
    cin >> n >> m;
    dir.assign(n, vi(m));
    F0R(i, n) {
        str s; cin >> s;
        F0R(j, m) dir[i][j]=ctoi[s[j]];
    }
    vis.assign(n, vb(m, false));
    tim.assign(n, vi(m, -1));
    len.assign(n, vi(m));
    F0R(x, n) F0R(y, m) if (!vis[x][y]) {
        vpi st; st.pb(mp(x, y)); tim[x][y]=0;
        while (! st.empty()) {
            int i = st.back().F, j = st.back().S;
            int ni=i+dx[dir[i][j]], nj=j+dy[dir[i][j]];
            if (!btw(ni, 0, n-1) || !btw(nj, 0, m-1)) {
                vis[i][j]=true;
                len[i][j]=1;
                st.pop_back();
            } else if (vis[ni][nj]) {
                len[i][j] = len[ni][nj]+1;
                vis[i][j]=true;
                st.pop_back();
            } else if (tim[ni][nj]>-1) {
                int tmp = tim[i][j]-tim[ni][nj]+1;
                pi cur = mp(-1, -1);
                while (cur.F != ni || cur.S != nj) {
                    cur = st.back();
                    len[cur.F][cur.S]=tmp; vis[cur.F][cur.S]=true;
                    st.pop_back();
                }
            } else {
                tim[ni][nj] = tim[i][j]+1;
                st.pb(mp(ni, nj));
            }
        }
    }
    int x=0, y=0;
    F0R(i, n) F0R(j, m) if (len[i][j]>len[x][y]) x=i, y=j;
    cout << x+1 << ' ' << y+1 << ' ' << len[x][y] << nl;
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