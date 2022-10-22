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
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()
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
 
//===================//
//  Added libraries  //
//===================//

// mod library
ll MOD=998244353 ;

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

//===================//
//end added libraries//
//===================//
 
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
 
const int MX = 1e6;
const int K = 20;

int n, m;
vii adj[MX];
ii dist[MX];
int DIST[MX][K];

void program() {
    IN(n,m);
    RE(i,m) {
        int u, v; IN(u,v);
        adj[u].pb({v,0});
        adj[v+n].pb({u+n,0});
    }
    RE1(i,n) adj[i].pb({i+n,1});
    RE1(i,n) adj[i+n].pb({i,1});

    priority_queue<iii,viii,greater<iii>> pq;
    RE1(i,n*2) dist[i] = {INF,INF};
    pq.push({0,0,1}); dist[1] = {0,0};
    while(!pq.empty()) {
        int d1, d2, u;
        tie(d1,d2,u) = pq.top(); pq.pop();
        if(dist[u] != ii(d1,d2)) continue;
        FOR(v,adj[u]) {
            ii nd = {v.se+d1,1-v.se+d2};
            if(nd < dist[v.fi]) {
                dist[v.fi] = nd;
                pq.push({nd.fi,nd.se,v.fi});
            }
        }
    }

    ii pAns = min(dist[n*2],dist[n]);
    mi ans = modpow(2,pAns.fi)-1+pAns.se;
    if(pAns.fi <= K) {
        RE1(i,n*2) RE(j,K) DIST[i][j] = INF;

        pq.push({0,1,0}); DIST[1][0] = 0;
        while(!pq.empty()) {
            int d, u, k;
            tie(d,u,k) = pq.top(); pq.pop();
            if(DIST[u][k] != d) continue;
            FOR(v,adj[u]) {
                int nk = v.se+k;
                int nd = d + 1 - v.se;
                if(v.se) nd += (1<<k);
                if(nk >= K) continue;
                if(nd < DIST[v.fi][nk]) {
                    DIST[v.fi][nk] = nd;
                    pq.push({nd,v.fi,nk});
                }
            }
        }

        RE(j,K) ans = min(int(ans), min(DIST[n][j], DIST[n*2][j]));
    }
    OUTL((ll)ans);
}