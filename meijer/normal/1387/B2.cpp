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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }

// output
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }

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

const int MX = 5e5;
int n, m=0;
vi adj[MX];
int SZ[MX];
ll ans=0;
vi f;
int a[MX];

int dfsSZ(int u, int p=0) {
    SZ[u] = 1;
    FOR(v,adj[u]) if(v!=p) SZ[u] += dfsSZ(v,u);
    FOR(v,adj[u]) if(v!=p) ans += 2*min(SZ[v], n-SZ[v]);
    return SZ[u];
}
int findCent(int u, int p=0) {
    FOR(v,adj[u]) if(v != p) if(SZ[v] > n/2) return findCent(v,u);
    return u;
}
void dfs(int u, int p=0) {
    f.pb(u);
    FOR(v,adj[u]) if(v != p) dfs(v,u);
}

void program() {
    IN(n);
    RE(i,n-1) {
        int u, v;
        IN(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfsSZ(1);
    int cent = findCent(1);
    FOR(v,adj[cent]) dfs(v, cent), m++;
    f.pb(cent);
    RE(i,n) a[f[i]] = f[(i+n/2)%n];
    OUT(ans,"\n");
    RE1(_pi,n) OUT(_pi==1?"":" ",a[_pi]); OUT("\n");
}