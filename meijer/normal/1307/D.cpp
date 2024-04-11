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

const int MX = 3e5;
int n, m, k, a[MX];
vi adj[MX];
int distToN[MX], distTo1[MX];

void program() {
	cin>>n>>m>>k;
	RE(i,k) cin>>a[i];

	RE(i,m) {
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	RE1(i,n) distToN[i]=distTo1[i]=-1;

	distToN[n] = 0;
	queue<int> q; q.push(n);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int v:adj[u])
			if(distToN[v] == -1)
				distToN[v] = distToN[u]+1, q.push(v);
	}

	distTo1[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int v:adj[u])
			if(distTo1[v] == -1)
				distTo1[v] = distTo1[u]+1, q.push(v);
	}

	int SA[MX];
	RE(i,k) SA[i]=i;
	sort(SA, SA+k, [](int i, int j) {
		return distTo1[a[j]]-distToN[a[j]] < distTo1[a[i]]-distToN[a[i]];
	});

	int ans=0, maxDistToN=-INF;
	RE(i,k) {
		int u=a[SA[i]];
		ans = max(ans, 1+distTo1[u]+maxDistToN);
		maxDistToN = max(maxDistToN, distToN[u]);
	}

	ans=min(ans, distToN[1]);
	cout<<ans<<endl;
}