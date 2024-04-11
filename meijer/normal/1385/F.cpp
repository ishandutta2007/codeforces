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
int n, k;
set<int> adj[MX];
vi leaves[MX];
queue<int> q;
bitset<MX> inQ;

void program() {
    cin>>testCases;
    inQ.reset();
    RE(TEST,testCases) {
        cin>>n>>k;
        RE1(i,n) adj[i].clear();
        RE1(i,n) leaves[i].clear();
        RE(i,n-1) {
            int u, v;
            cin>>u>>v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        if(k == 1) {
            cout<<n-1<<endl;
            continue;
        }

        RE1(i,n) if(adj[i].sz == 1) leaves[*adj[i].begin()].pb(i);
        RE1(i,n) if(leaves[i].sz >= k && !inQ[i]) q.push(i), inQ[i]=1;

        int ans=0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            inQ[u] = 0;
            while(leaves[u].sz >= k) {
                ans++;
                RE(i,k) {
                    int v = leaves[u].back(); leaves[u].pop_back();
                    adj[u].erase(v);
                    adj[v].erase(u);
                }
            }
        
            if(adj[u].sz == 1) {
                int v = *adj[u].begin();
                leaves[v].pb(u);
                if(leaves[v].sz >= k && !inQ[v]) q.push(v), inQ[v]=1;
            }
        }

        cout<<ans<<endl;
    }
}