#include <bits/stdc++.h>
using namespace std;
 
// macros
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e18
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }
 
// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const vector<T>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
template<class T> void OUT(const vector<T>& x) {RE(i,x.size()) OUT(i==0?"":" ",x[i]);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }
template<class H> void OUTLS(const H& h) {OUTL(h); }
template<class H, class... T> void OUTLS(const H& h, const T&... t) {OUT(h,' '); OUTLS(t...); }
 
// dp
template<class T> bool ckmin(T&a, T&b) { bool bl = a > b; a = min(a,b); return bl;}
template<class T> bool ckmax(T&a, T&b) { bool bl = a < b; a = max(a,b); return bl;}
 
void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}
 
 
//===================//
//   begin program   //
//===================//


// mod library
ll MOD=998244353;

inline ll mod(ll x_) {
    return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;


const int MX = 410;
const int N = (1<<20);

int n, m;
vi adj[MX];
int dist[MX];
int distX[MX], distY[MX];
int cnt[MX][MX][MX];
int ans[MX][MX];

void fillDist(int root) {
    RE1(i,n) dist[i] = -1;
    queue<int> q; q.push(root); dist[root] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        FOR(v,adj[u]) {
            if(dist[v] != -1) continue;
            dist[v] = dist[u]+1;
            q.push(v);
        }
    }
}

mi get(int x, int y) {
    fillDist(x); RE1(i,n) distX[i] = dist[i];
    fillDist(y); RE1(i,n) distY[i] = dist[i];

    int distXY = distX[y];
    int onPath = 0;
    RE1(i,n) if(distX[i] + distY[i] - 1 == distXY) onPath++;
    if(onPath != distXY) return 0;

    // fill cnt
    RE1(i,n) cnt[distX[i]][distY[i]][i] = 1;

    mi res = 1;
    RE1(i,n) {
        if(distX[i] + distY[i] - 1 != distXY) {
            int a=distX[i], b=distY[i];
            int ways = 0;
            FOR(v,adj[i]) ways += cnt[a-1][b-1][v];
            res *= mi(ways);
        }
    }

    // reset cnt
    RE1(i,n) cnt[distX[i]][distY[i]][i] = 0;

    return res;
}

void program() {
    RE(i,MX) RE(j,MX) RE(k,MX) cnt[i][j][k] = 0;
    IN(n,m);
    RE(i,m) {
        int u, v; IN(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    RE1(i,n) REP(j,i,n+1) ans[i][j] = ans[j][i] = get(i,j);
    RE1(i,n) {
        RE1(j,n) OUT(j==1?"":" ", ans[i][j]);
        OUTL();
    }
}