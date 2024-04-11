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
int testCases;
int n, m;
set<int> adj[MX];
vi ex[MX], rev[MX];
bitset<MX> visited;
int cnt[MX];
 
void dfs(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    for(int v:adj[u]) {
        adj[v].erase(u);
        ex[v].push_back(u);
        rev[u].push_back(v);
    }
    adj[u].clear();
    for(int v:rev[u]) cnt[v]++;
    for(int v:rev[u]) if(cnt[v] == ex[v].sz) dfs(v);
}
 
int col[MX];
bool pos;
void proc(int u) {
    if(col[u] == 1) {
        pos = 0;
        return;
    }
    col[u] = 1;
    for(int v:ex[u]) {
        if(col[v] == 2) continue;
        proc(v);
        if(!pos) return;
    }
    col[u] = 2;
}
 
void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>m;
        RE1(i,n) cnt[i] = 0;
        RE1(i,n) ex[i].clear();
        RE1(i,n) adj[i].clear();
        RE1(i,n) rev[i].clear();
        RE(i,m) {
            int t,u,v;
            cin>>t>>u>>v;
            if(!t) {
                adj[u].insert(v);
                adj[v].insert(u);
            } else {
                ex[u].pb(v);
                rev[v].pb(u);
            }
        }
 
        RE1(i,n) visited[i] = 0;
        RE1(i,n) if(ex[i].sz == cnt[i]) dfs(i);

        pos = 1;
        RE1(i,n) col[i] = 0;
        RE1(i,n) if(adj[i].sz) pos = 0;
        RE1(i,n) proc(i);
 
        cout<<(pos ? "Yes" : "No")<<endl;
        if(pos) RE1(u,n) {
            for(int v:ex[u]) cout<<u<<" "<<v<<endl;
        }
    }
}