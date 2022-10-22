#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
//macros
typedef long long ll;
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
#define INF 1e10
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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
const ll EPS = 1e-16;
 
int n, m;
vii adj[MX];
ll x[MX], a[MX], b[MX];
bitset<MX> visited;
ll mustX = -INF;
vector<ll> f;
bool possible = 1;
 
void resetVisited(int u) {
    if(!visited[u]) return;
    visited[u] = 0;
    for(ii v:adj[u]) resetVisited(v.fi);
}
void dfsXA(int u, ll nx, ll na) {
    if(visited[u]) {
        if(x[u] == nx) {
            if(a[u] != na) possible = 0;
        } else {
            mustX = (na - a[u])*2/(x[u]-nx);
        }
        return;
    }
    visited[u] =  1;
    x[u] = nx;
    a[u] = na;
    for(ii p : adj[u]) {
        int v = p.fi;
        ll c = p.se;
        dfsXA(v, -nx, c-na);
    }
}
bool dfsPossible(int u) {
    if(visited[u]) return 1;
    visited[u] = 1;
    for(ii p:adj[u]) {
        int v = p.fi;
        ll c = p.se;
        if(!dfsPossible(v)) return 0;
        if(b[u] + b[v] != 2*c) return 0;
    }
    return 1;
}
ll dfsSet(int u, ll X) {
    if(visited[u]) return 0;
    visited[u] = 1;
    b[u] = x[u]*X + a[u]*2;
    ll ans = fabs(b[u]);
    for(ii v:adj[u]) ans += dfsSet(v.fi, X);
    return ans;
}
ll getTot(int u, ll X) {
    resetVisited(u);
    return dfsSet(u, X);
}
void dfsList(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    f.pb(-x[u]*a[u]);
    for(ii v:adj[u]) dfsList(v.fi);
}
 
int SA[MX];

void program() {
    scanf("%d%d", &n, &m);
    RE(i,m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }

    visited.reset();
    RE1(u,n) {
        if(visited[u]) continue;
        possible = 1;
        mustX = -INF;
        dfsXA(u, 1, 0);
        if(!possible) {
            cout<<"NO\n";
            return;
        }
        if(mustX != -INF) {
            resetVisited(u);
            dfsSet(u, mustX);
            resetVisited(u);
            if(!dfsPossible(u)) {
                cout<<"NO\n";
                return;
            }
        } else {
            f.clear();
            resetVisited(u);
            dfsList(u);
            sort(f.begin(), f.end());

            int N = f.sz;

            ll best = f[(N-1)/2];

            getTot(u, best*2);
        }
    }
    cout<<"YES\n";
    RE1(i,n) {
        if(i != 1) cout<<" ";
        cout<<(double)(b[i])/2.0;
    }
    cout<<"\n";
}