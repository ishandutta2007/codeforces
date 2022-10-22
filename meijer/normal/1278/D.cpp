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
int n, l, r;
bool isBeg[MX];
int End[MX];
int idx[MX];
vi adj[MX/2];
bitset<MX/2> visited;

void dfs(int u) {
	if(visited[u]) return;
	visited[u] = 1;
	for(int v:adj[u])
		dfs(v);
}

void program() {
	cin>>n;
	RE(i,n) {
		cin>>l>>r;
		isBeg[l]=1;
		End[l] = r;
		idx[l] = i;
	}
	bool pos = 1;
	int edges=0;
	map<int, int> m;
	REP(i,1,n*2+1) {
		if(isBeg[i]) {
			// begin
			for(ii p : m) {
				if(p.fi > End[i])
					break;
				adj[idx[i]].pb(p.se);
				adj[p.se].pb(idx[i]);
				edges++;
				if(edges == n) break;
			}
			m[End[i]] = idx[i];
			if(edges == n) break;
		} else {
			// end
			m.erase(i);
		}
	}
	if(edges == n) pos = 0;
	dfs(0);
	if(visited.count() != n) pos=0;
	cout<<(pos?"YES":"NO")<<endl;
}