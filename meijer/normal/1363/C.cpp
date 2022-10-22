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
int testcases, n, x;
vi adj[MX], chl[MX];
int p[MX];
int SZ[MX];

void dfsChl(int u, int parent) {
    p[u] = parent;
    SZ[u] = 1;
    for(int v:adj[u]) if(v != parent) dfsChl(v, u), chl[u].pb(v), SZ[u] += SZ[v];
}

void program() {
    cin>>testcases;
    while(testcases--) {
        cin>>n>>x;
        RE(i,n+2) adj[i].clear(), chl[i].clear();
        RE(i,n-1) {
            int u, v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfsChl(x, -1);
        bool winner = 1;
        for(int v:adj[x]) {
            if(SZ[v]&1) winner ^= 1;
        }
        if(adj[x].sz <= 1) winner = 0;
        cout<<(winner?"Ashish":"Ayush")<<endl;
    }
}