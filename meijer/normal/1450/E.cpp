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
 
const int MX = 300;

int n, m;
vii adj[MX];
int a[MX];
int col[MX];
int dist[MX][MX];

bool dfs(int u, int c) {
    col[u]=c;
    FOR(v,adj[u]) {
        if(col[v.fi] == -1) {
            if(dfs(v.fi,!c)) return 1;
        } else {
            if(col[v.fi]==c) return 1;
        }
    }
    return 0;
}
bool isPartite() {
    RE1(i,n) col[i]=-1;
    return !dfs(1,0);
}

void program() {
    IN(n,m);
    RE(i,m) {
        int u, v, d;
        IN(u,v,d);
        if(d) {
            adj[u].pb({v, 1});
            adj[v].pb({u,-1});
        } else {
            adj[u].pb({v, 1});
            adj[v].pb({u, 1});
        }
    }

    if(!isPartite()) {
        OUTL("NO");
        return;
    }

    RE1(i,n) RE1(j,n) dist[i][j] = 1e6;
    RE1(i,n) dist[i][i] = 0;
    RE1(i,n) FOR(v,adj[i]) dist[i][v.fi] = v.se;

    RE1(k,n) RE1(i,n) RE1(j,n) {
        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
        dist[i][j]=max(dist[i][j],int(-1e6));
    }

    bool changed=0;
    RE1(k,n) RE1(i,n) RE1(j,n) if(dist[i][j] > dist[i][k]+dist[k][j]) changed = 1;

    if(changed) {
        OUTL("NO");
        return;
    }

    OUTL("YES");
    int best=0, x=0;
    RE1(i,n) RE1(j,n) {
        if(dist[i][j] >= best) {
            best = dist[i][j];
            x = i;
        }
    }
    OUTL(best);
    RE1(i,n) OUT(i==1?"":" ", dist[x][i]);
    OUTL();
}