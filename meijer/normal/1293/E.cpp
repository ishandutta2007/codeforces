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

//===================//
//  Added libraries  //
//===================//

int LOG2(int _X) {return _X < 2 ? 0 : 1 + LOG2(_X/2);}

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 4000;
ll dp[MX][MX];
ll n;
vi adj[MX];
ll parent[MX][MX], subSz[MX][MX];

void dfsParent(int root, int u, int p=-1) {
	parent[root][u] = p;
	for(int v:adj[u]) if(v != p) {
		dfsParent(root, v, u);
	}
}
void dfsSubSz(int root, int u, int p=-1) {
	subSz[root][u] = 1;
	for(int v:adj[u]) if(v != p) {
		dfsSubSz(root, v, u);
		subSz[root][u] += subSz[root][v];
	}
}
ll getAns(int u, int v) {
	if(dp[u][v] == -1) {
		if(u == v) {
			dp[u][v] = 0;
		} else {
			dp[u][v] = subSz[v][u]*subSz[u][v] + max(getAns(u, parent[u][v]), getAns(v, parent[v][u]));
		}
	}
	return dp[u][v];
}

void program() {
	cin>>n;
	RE(i,n-1) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	RE(i,n) RE(j,n) dp[i][j] = -1;
	RE(u,n) dfsParent(u, u);
	RE(u,n) dfsSubSz(u, u);
	ll ans=0;
	RE(i,n) RE(j,n) ans=max(ans, getAns(i,j));
	cout<<ans<<endl;
}