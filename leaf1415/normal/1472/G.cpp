#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;


struct SCC{
	int n;
	vector<vector<int> > G, revG;
	vector<int> used, scc, topo;
	int sccid;
	
	void tpdfs(int v)
	{
		used[v] = 1;
		for(int i = 0; i < G[v].size(); i++){
			if(!used[G[v][i]]) tpdfs(G[v][i]);
		}
		topo.push_back(v);
	}
	void sccdfs(int v, int id)
	{
		used[v] = 1;
		scc[v] = id;
		for(int i = 0; i < revG[v].size(); i++){
			if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
		}
	}
	
	SCC(){}
	SCC(int n){ 
		this->n = n;
		G.resize(n+1);
		revG.resize(n+1);
		used.resize(n+1);
		scc.resize(n+1);
	}
	init(){
		for(int i = 1; i <= n; i++){
			G[i].clear(), revG[i].clear();
			used[i] = 0;
		}
		topo.clear();
	}
	void add_edge(int u, int v)
	{
		G[u].push_back(v);
	}
	void tpsort()
	{
		topo.clear();
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 1; i <= n; i++) if(!used[i]) tpdfs(i);
		reverse(topo.begin(), topo.end());
	}
	int calcSCC(){ 
		for(int i = 1; i <= n; i++) revG[i].clear();
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < G[i].size(); j++){
				revG[G[i][j]].push_back(i);
			}
		}
		sccid = 0;
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], sccid++);
		return sccid;
	}
	bool checkDAG(){ 
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 0; i < topo.size(); i++){
			int v = topo[i];
			used[v] = 1;
			for(int j = 0; j < G[v].size(); j++){
				if(used[G[v][j]]) return false;
			}
		}
		return true;
	}
};

ll Q;
ll n, m;
vector<ll> G[200005];
ll dist[200005];
ll dp[200005];

void bfs(vector<llint> G[], int S, llint dist[])
{
	queue<int> Q;
	Q.push(S);
	
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i]] < inf/2) continue;
			Q.push(G[v][i]);
			dist[G[v][i]] = dist[v] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	while(Q--){
		cin >> n >> m;
		rep(i, 1, n) G[i].clear();
		ll u, v;
		rep(i, 1, m){
			cin >> u >> v;
			G[u].push_back(v);
		}
		bfs(G, 1, dist);
		
		rep(i, 1, n){
			dp[i] = dist[i];
			for(auto u : G[i]) chmin(dp[i], dist[u]);
		}
		
		SCC scc(n);
		rep(i, 1, n){
			 for(auto u : G[i]) if(dist[i] < dist[u]) scc.add_edge(i, u);
		}
		scc.tpsort();
		
		for(int i = n-1; i >= 0; i--){
			ll v = scc.topo[i];
			//cout << v << " " << dp[v] << endl;
			for(auto u : scc.G[v]){
				chmin(dp[v], dp[u]);
			}
		}
		rep(i, 1, n) cout << dp[i] << " "; cout << endl;
	}
	
	return 0;
}