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

const int MX = 3e5;
int n;
set<int> adj[MX];
stack<int> path;

ii dfsFurthest(int u, int p = 0) {
	ii ans = {0,u};
	for(int v:adj[u]) {
		if(v == p) continue;
		ii p = dfsFurthest(v,u);
		p.fi++;
		ans = max(ans, p);
	}
	return ans;
}
bool destroyPath(int u, int t, int p=0) {
	if(u == t) return true;
	for(int v:adj[u]) {
		if(v == p) continue;
		if(destroyPath(v, t, u)) {
			path.push(v);
			adj[u].erase(v);
			adj[v].erase(u);
			return true;
		}
	}
	return false;
}

void program() {
	cin>>n;
	RE(i,n-1) {
		int u, v; cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	ii a = dfsFurthest(1);
	ii b = dfsFurthest(a.se);
	int A=a.se, B=b.se, C=1;
	if(C == A) C=2;
	if(C == B) C=3;
	if(C == A) C=2;
	destroyPath(A, B);
	int maxAns = b.fi;
	while(!path.empty()) {
		int u = path.top(); path.pop();
		ii p = dfsFurthest(u);
		int cAns = b.fi + p.fi;
		if(cAns > maxAns) {
			maxAns = cAns;
			C = p.se;
		}
	}
	cout<<maxAns<<endl;
	cout<<A<<" "<<B<<" "<<C<<endl;
}