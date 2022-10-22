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
int n;
vi adj[MX];
int ans[MX];

void program() {
	cin>>n;
	RE(i,n-1) {
		int u, v; cin>>u>>v;
		adj[u].pb(i);
		adj[v].pb(i);
	}
	RE(i,n-1) ans[i] = -1;
	int cur = 0;
	RE(i,n) if(adj[i].size() >= 3) {
		ans[adj[i][0]] = 0;
		ans[adj[i][1]] = 1;
		ans[adj[i][2]] = 2;
		cur = 3;
		break;
	}
	RE(i,n-1) if(ans[i] == -1) ans[i] = cur++;
	RE(i,n-1) cout<<ans[i]<<endl;
}