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

int n, u, v, tim, ldep;
vi c, st, ed, ord, dep, subcnt;
vll cnt;
vvi adj, up;

void dfs(int i, int parent, int d) {
    debug(i, parent);
    up[i][0]=parent;
    st[i]=tim++;
    ord.pb(i);
    dep[i] = d;
    subcnt[i] = c[i];
    for (int nb : adj[i]) if (nb!=parent) {
        dfs(nb, i, d+1);
        subcnt[i] += subcnt[nb];
    }
    ed[i]=tim;
}
void init(int root) {
    ldep=tim=0;
    while (pow(2, ldep) <= n) ldep++; ldep++;
    st.rsz(n), ed.rsz(n); up.assign(n, vi(ldep)); ord.clear(); dep.rsz(n); subcnt.rsz(n);
    dfs(root, root, 0);
    FOR(i, 1, up[0].size()) F0R(j, n) up[j][i] = up[up[j][i-1]][i-1];
}
int goup(int i, int k) { F0R(d, ldep) if (k&1<<d) i=up[i][d]; return i; }
bool anc(int i, int j) {return st[i]<=st[j] && ed[i]>=ed[j];}
int lca(int i, int j) {
    if (anc(i, j)) return i;
    R0F(d, ldep) if (! anc(up[i][d], j)) i=up[i][d];
    return up[i][0];
}

int countadj(int i) {
    int ans = 0;
    for (int nb : adj[i]) if (c[nb]==1) ans++;
    return ans;
}
void dfs2(int i, int p) {
    if (c[i]==0) {
        int numadj = countadj(i);
        if (numadj>1) cnt[0]++;
        else if (numadj==1) {
            cnt[st[i]]++; cnt[st[i]+1]--;
            vi valid;
            for (int nb : adj[i]) if (c[nb]==0) {
                if (nb==p && subcnt[i]<subcnt[0]) valid.pb(nb);
                else if (nb != p && subcnt[nb]>0) valid.pb(nb);
            }
            if (valid.size()>1) cnt[0]++;
            else if (valid.size()==1) {
                for (int nb : adj[i]) if (nb != p && nb != valid[0]) {
                    cnt[st[nb]]++;
                    cnt[ed[nb]]--;
                }
                if (p != valid[0]) {
                    cnt[0]++;
                    cnt[st[i]]--;
                    cnt[ed[i]]++;
                }
            }
        }
    }
    for (int nb : adj[i]) if (nb != p) dfs2(nb, i);
}

void solve() {
    cin >> n;
    read(c, n);
    adj.clear(); adj.rsz(n);
    F0R(i, n-1) {
        cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    init(0);
    cnt.assign(n+1, 0);
    vi tmp; int top = -1;
    for (int i : ord) {
        if (c[i]==1) {
            if (top==-1) top = i;
            while (!tmp.empty() && !anc(tmp.back(), i)) tmp.pop_back();
            if (i != top) {
                cnt[st[i]]++;
                cnt[ed[i]]--;
            }
            if (!tmp.empty()) {
                cnt[0]++;
                int j = goup(i, dep[i]-dep[tmp.back()]-1);
                cnt[st[j]]--;
                cnt[ed[j]]++;
            }
            tmp.pb(i);
        }
    }
    if (tmp.empty() || tmp[0] != top) {
        cnt[st[top]]++;
        cnt[ed[top]]--;
    }
    dfs2(0, 0);
    FOR(i, 1, n+1) cnt[i] += cnt[i-1];
    F0R(i, n) cout << min(1ll, cnt[st[i]]) << ' ';
    cout << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    while (t--) {
        solve();
    }
}