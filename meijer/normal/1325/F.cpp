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
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, m, minN;
vi adj[MX];
bitset<MX> used;
int SA[MX];
int sz[MX];
stack<int> ansAdd;

bool dfs(int u, int target) {
	if(u == target) return 1;
	if(used[u]) return 0;
	used[u] = 1;
	for(int v:adj[u]) {
		if(dfs(v, target)) {
			ansAdd.push(u);
			return 1;
		}
	}
	return 0;
}

void program() {
	cin>>n>>m;
	RE(i,m) {
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i,1,n) if(i*i >= n) {
		minN = i;
		break;
	}
	int maxN=0;
	REP(i,1,n) if(i*i <= n) {
		maxN = i;
	}
	{
		// ind set
		set<int> ans;
		used.reset();
		RE1(i,n) sz[i] = adj[i].size();
		priority_queue<ii, vii, greater<ii>> pq;
		RE1(i,n) pq.push({sz[i], i});
		while(!pq.empty()) {
			ii p = pq.top(); pq.pop();
			if(used[p.se]) continue;
			ans.insert(p.se);
			if(ans.size() == minN) break;
			used[p.se] = 1;
			for(int v:adj[p.se]) if(!used[v]) {
				used[v] = 1;
				for(int w:adj[v]) if(!used[w]) {
					sz[w]--;
					pq.push({sz[w], w});
				}
			}
		}
		bool f=1;
		if(ans.size() == minN) {
		cout<<1<<endl;
		for(int v:ans) cout<<(f?"":" ")<<v, f=0; cout<<endl;
		return;
		}
	}
		cout<<2<<endl;
	while(1) {
		vi ans;
		used.reset();
		int u=(rng()%n)+1;
		RE(i,minN) {
			used[u] = 1;
			ans.pb(u);
			int nu=-1;
			vi pos;
			for(int v:adj[u]) if(!used[v]) pos.pb(v);
			if(pos.size() == 0) break;
			u = pos[rng()%pos.size()];
		}
		used[ans.back()] = 0;
		if(!dfs(ans.back(), *ans.begin())) continue;
		bool f=1;
		while(!ansAdd.empty()) {
			if(!f) ans.pb(ansAdd.top());
			f=0;
			ansAdd.pop();
		}
		f=1;
		if(ans.size() < minN) continue;
		cout<<ans.size()<<endl;
		for(int v:ans) cout<<(f?"":" ")<<v, f=0; cout<<endl;
		return;
	}
}