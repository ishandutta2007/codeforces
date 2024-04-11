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
int n;
set<int> adj[MX];
set<int> leaves[MX];
int a[MX];
int ans=0;
queue<int> q;
bitset<MX> visited;

void removeNode(int u) {
    for(int v:adj[u]) {
        adj[v].erase(u);
        leaves[v].erase(u);
        if(adj[v].sz == 1) {
            int w = *adj[v].begin();
            leaves[w].insert(v);
            if(leaves[w].sz && leaves[w].sz >= adj[w].sz-1) q.push(w);
        }
        if(leaves[v].sz && leaves[v].sz >= adj[v].sz-1) q.push(v);
    }
    adj[u].clear();
}

void program() {
    cin>>n;
    RE(i,n-1) {
        int u, v;
        cin>>u>>v; u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    visited.reset();
    RE(i,n) if(adj[i].sz == 1) leaves[*adj[i].begin()].insert(i);
    RE(i,n) if(leaves[i].sz && leaves[i].sz >= adj[i].sz-1) q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(visited[u]) continue;
        visited[u] = 1;
        for(int v:leaves[u]) visited[v] = 1;
        ans += (leaves[u].sz - 1)*2;
        ans += 2;
        auto it = leaves[u].begin();
        a[u] = *it;
        while(it != --leaves[u].end()) {
            auto prev = it;
            it++;
            a[*prev] = *it;
        }
        a[*it] = u;
        removeNode(u);
    }

    RE(i,n) a[i]++;

    cout<<ans<<endl;
    RE(_pi,n) cout<<(_pi==0?"":" ")<<a[_pi]; cout<<endl;
}