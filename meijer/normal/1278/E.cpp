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

const int MX=1e6+1e5;
int n;
vi adj[MX];
int lastUsed;
ii ans[MX];

void dfs(int u, int p=-1) {
	REV(i,0,adj[u].size()) {
		int v=adj[u][i];
		if(v != p)
			ans[v].se = lastUsed--;
	}

	ans[u].fi = lastUsed--;

	for(int v:adj[u])
		if(v != p)
			dfs(v, u);
}

void program() {
	cin>>n;
	RE(i,n-1) {
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	lastUsed = n*2;
	ans[1].se = lastUsed--;
	dfs(1);
	REI(i,1,n) {
		cout<<ans[i].fi<<" "<<ans[i].se<<endl;
	}
}