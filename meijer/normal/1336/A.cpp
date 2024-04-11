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

int n, k;
vi adj[MX], chl[MX];
int SIZE[MX];
int depth[MX];
priority_queue<ll> pq;

void dfsChl(int u, int p) {
    depth[u] = depth[p]+1;
    SIZE[u] = 1;
    for(int v:adj[u]) if(v!=p) dfsChl(v,u), chl[u].pb(v);
    for(int v:chl[u]) SIZE[u] += SIZE[v];
}

void program() {
    cin>>n>>k;
    RE(i,n-1) {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    depth[0] = 0;
    dfsChl(1,0);
    RE1(i,n) pq.push(depth[i]-SIZE[i]);
    ll ans=0;
    RE(i,k) {
        ans += pq.top(); pq.pop();
    }
    cout<<ans<<endl;
}