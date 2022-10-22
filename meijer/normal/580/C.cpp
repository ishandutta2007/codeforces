#include <bits/stdc++.h>
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
#define INF 1e9
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
int n, m, a[MX];
vi adj[MX], chl[MX];
int p[MX];
int ans=0;

void dfsChl(int u, int parent) {
    p[u] = parent;
    for(int v:adj[u]) if(v != parent) dfsChl(v, u), chl[u].pb(v);
}
void dfs(int u, int con) {
    if(a[u]) con++;
    else con = 0;
    if(con > m) return;
    if(chl[u].sz == 0) {
        ans++;
    }
    for(int v:chl[u]) dfs(v, con);
}

void program() {
    cin>>n>>m;
    RE1(i,n) cin>>a[i];
    RE(i,n-1) {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfsChl(1, -1);
    dfs(1, 0);
    cout<<ans<<endl;
}