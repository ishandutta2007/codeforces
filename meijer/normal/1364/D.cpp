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
int n, m, k, edges = 0;
set<int> adj[MX], chl[MX];
bitset<MX> visited;
int nxt[MX], start;
int dp[MX][2];
bool dpA[MX][2];
vi ans;
bitset<MX> incl;
int countIncl = 0;

void dfsChildren(int u, int p) {
    for(int v:adj[u]) if(v != p) dfsChildren(v, u), chl[u].insert(v);
}
int getDP(int u, bool p) {
    if(dp[u][p] != -1) return dp[u][p];

    int ans = 0;
    dpA[u][p] = 1;

    // include u
    if(!p) {
        int cur = 1;
        for(int v:chl[u]) cur += getDP(v, 1);
        ans = cur;
    }

    // dont include u
    int cur = 0;
    for(int v:chl[u]) cur += getDP(v, 0);
    if(cur >= ans) {
        ans = cur;
        dpA[u][p] = 0;
    }

    return dp[u][p] = ans;
}
void findDP(int u, bool p) {
    if(dpA[u][p])
        ans.pb(u);
    for(int v:chl[u]) findDP(v, dpA[u][p]);
}

bool dfsC(int u, int p) {
    if(visited[u]) {
        start = u;
        return 1;
    }
    visited[u] = 1;
    for(int v:adj[u]) if(v != p) {
        if(dfsC(v, u)) {
            nxt[u] = v;
            return 1;
        }
    }
    visited[u] = 0;
    return 0;
}
void dfs(int u) {
    if(incl[u]) return;
    if(countIncl == k) return;
    incl[u] = 1;
    countIncl++;
    for(int v:adj[u]) dfs(v);
}
void removeNode(int u) {
    for(int v:adj[u]) adj[v].erase(u), edges--;
    adj[u].clear();
}

void program() {
    cin>>n>>m>>k;
    edges = m;
    RE(i,m) {
        int u, v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    incl.reset();
    dfs(1);
    RE1(i,n) if(!incl[i]) removeNode(i);
    
    if(edges == k-1) {
        // tree
        cout<<1<<endl;
        
        int indS = (k+1)/2;
        dfsChildren(1, -1);
        RE(i,n+2) RE(j,2) dp[i][j] = -1;
        getDP(1, 0);
        findDP(1, 0);
        assert(ans.sz >= indS);
        RE(_pi,indS) cout<<(_pi==0?"":" ")<<ans[_pi]; cout<<endl;

    } else {
        // cycle
        cout<<2<<endl;

        visited.reset();
        dfsC(1, -1);
        visited.reset();
        dfsC(start, -1);
        int u = start;
        do {
            ans.pb(u);
            u = nxt[u];
        } while(u != start);
        assert(ans.sz >= 3);
        cout<<ans.sz<<endl;
        RE(_pi,ans.sz) cout<<(_pi==0?"":" ")<<ans[_pi]; cout<<endl;
    }
}