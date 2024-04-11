#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
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
int n, a[MX], b[MX], c[MX];
vi adj[MX], chl[MX];
int p[MX];
int cnta[MX], cntb[MX];
int depth[MX];
bitset<MX> visited;

void dfsChl(int u, int parent, int D=1) {
    p[u] = parent;
    a[u] = min(a[u], a[parent]);
    depth[u] = D;
    for(int v:adj[u]) if(v != parent) dfsChl(v, u, D+1), chl[u].pb(v);
}

void program() {
    cin>>n;
    RE1(i,n) cin>>a[i]>>b[i]>>c[i];
    RE(i,n-1) {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    a[0] = INF;
    dfsChl(1, 0);
    RE1(i,n) cnta[i]=cntb[i]=0;
    RE1(i,n) if(b[i]==0 && c[i]==1) cnta[i]++;
    RE1(i,n) if(b[i]==1 && c[i]==0) cntb[i]++;

    ll ans = 0;
    priority_queue<ii> q;
    visited.reset();
    RE1(i,n) q.push({depth[i], i});
    while(!q.empty()) {
        int u=q.top().se; q.pop();
        if(u == 0) break;
        while(cnta[u] && cntb[u]) cnta[u]--, cntb[u]--, ans += a[u]*2;
        cnta[p[u]] += cnta[u];
        cntb[p[u]] += cntb[u];
        visited[p[u]] = 1;
    }
    if(cnta[0] || cntb[0]) {
        cout<<-1<<endl;
        return;
    }

    cout<<ans<<endl;
}