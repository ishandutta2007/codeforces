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

const int MX = 1e6+5;
int n;
int a[MX];
bitset<MX> isPrime;
vi primeFact[MX];
vi adj[MX];
bitset<MX> visited;
int depth[MX];
int ans=INF;

int bfs(int start) {
	visited.reset();
	queue<ii> q; q.push({start,-1});
	depth[start] = 0;
	visited[start] = 1;
	while(!q.empty()) {
		int u, p;
		tie(u,p) = q.front(); q.pop();
		for(int v:adj[u]) {
			if(v == p) continue;
			if(visited[v]) {
				ans = min(ans,depth[u]+depth[v]+1);
			} else {
				depth[v] = depth[u]+1;
				visited[v] = 1;
				q.push({v,u});
			}
		}
	}
	return INF;
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	REP(i,2,MX) isPrime[i] = 1;
	REP(i,2,MX) {
		if(!isPrime[i]) continue;
		for(int j=i*2; j<MX; j+=i) isPrime[j] = 0;
	}
	REP(i,2,1001) {
		if(!isPrime[i]) continue;
		int sq = i*i;
		RE(j,n) while((a[j]%sq) == 0) {
			a[j] /= sq;
		}
	}
	RE(i,n) {
		if(a[i] == 1) {
			cout<<1<<endl;
			return;
		}
	}
	set<int> s;
	RE(i,n) {
		if(s.count(a[i])) {
			cout<<2<<endl;
			return;
		}
		s.insert(a[i]);
	}
	REP(i,2,1001) {
		if(!isPrime[i]) continue;
		RE(j,n) {
			if((a[j] % i) == 0) {
				adj[a[j]/i].pb(i);
				adj[i].pb(a[j]/i);
				a[j] = 1;
			}
		}
	}
	RE(j,n) if(a[j] != 1) {
		adj[1].pb(a[j]);
		adj[a[j]].pb(1);
	}
	REP(i,1,1001) {
		ans = min(bfs(i), ans);
	}
	if(ans == INF) ans = -1;
	cout<<ans<<endl;
}