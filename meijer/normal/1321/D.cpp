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
int n, m, k, p[MX], s, t, dist[MX];
vi adj[MX];
set<int> nxt[MX];

void program() {
	cin>>n>>m;
	RE(i,m) {
		int u, v; cin>>u>>v; u--; v--;
		adj[v].pb(u);
	}
	cin>>k;
	RE(i,k) cin>>p[i], p[i]--;
	s = p[0], t = p[k-1];
	RE(i,n) dist[i] = -1;
	queue<int> q; q.push(t), dist[t]=0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v:adj[u]) {
			if(dist[v] == -1) {
				dist[v] = dist[u]+1;
				q.push(v);
				nxt[v].insert(u);
			} else {
				if(dist[v] == dist[u]+1)
					nxt[v].insert(u);
			}
		}
	}
	int mn=0, mx=0;
	RE(i,k-1) {
		if(nxt[p[i]].count(p[i+1])) {
			if(nxt[p[i]].size() >= 2) mx++;
		} else {
			mn++, mx++;
		}
	}
	cout<<mn<<" "<<mx<<endl;
}