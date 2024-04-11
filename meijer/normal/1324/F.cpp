#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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

const int MX = 5e5;
int n, a[MX];
vi adj[MX];
vi chl[MX];
int par[MX];
int maxDifTree[MX];
int maxUp[MX];

void dfsChl(int u=1, int p=0) {
	par[u] = p;
	for(int v:adj[u]) if(v != p) dfsChl(v,u), chl[u].pb(v);
}
void dfsMaxDifTree(int u=1) {
	maxDifTree[u] = (a[u] ? 1 : -1);
	for(int v:chl[u]) {
		dfsMaxDifTree(v);
		maxDifTree[u] += max(0,maxDifTree[v]);
	}
}
void dfsMaxUp(int u=1) {
	maxUp[u] = 0;
	if(par[u] != 0) {
		int mx = maxUp[par[u]];
		mx += maxDifTree[par[u]];
		mx -= max(0,maxDifTree[u]);
		maxUp[u] = max(maxUp[u], mx);
	}
	for(int v:chl[u]) {
		dfsMaxUp(v);
	}
}

void program() {
	cin>>n;
	RE1(i,n) cin>>a[i];
	RE(i,n-1) {
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfsChl();
	dfsMaxDifTree();
	dfsMaxUp();
	RE1(i,n) {
		cout<<(i==1?"":" ");
		int ans=0;
		ans = (a[i] ? 1 : -1);
		ans += maxUp[i];
		for(int v:chl[i]) ans += max(0,maxDifTree[v]);
		cout<<ans;
	}
	cout<<endl;
}