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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define PI 3.1415926535897932384626433

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;


struct SCC{
	int n;
	vector<vector<int> > G, revG, compG;
	vector<int> used, scc, topo;
	int sccid, sccnum;
	
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
	SCC(int n){  //V(G) = {1, 2, ..., n}, n
		this->n = n;
		G.resize(n+1);
		revG.resize(n+1);
		used.resize(n+1);
	}
	void init(){
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
	bool checkDAG(){ //tpsort()DAGtrue
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
	int calcSCC(){  //tpsort()SCCSCC-ID1-indexed
		scc.resize(n+1);
		for(int i = 1; i <= n; i++) revG[i].clear();
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < G[i].size(); j++){
				revG[G[i][j]].push_back(i);
			}
		}
		sccid = 1;
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], sccid++);
		return sccnum = sccid-1;
	}
	void compressSCC(bool simple = false){ //calcSCC()scc::compG
		compG.resize(sccnum+1);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < G[i].size(); j++){
				int u = G[i][j];
				if(scc[i] != scc[u]) compG[scc[i]].push_back(scc[u]);
			}
		}
		if(simple){
			for(int i = 1; i <= sccnum; i++){
				sort(compG[i].begin(), compG[i].end());
				compG[i].erase(unique(compG[i].begin(), compG[i].end()), compG[i].end());
			}
		}
	}
	
};

ll n;
ll x[1005], y[1005], r[1005], dist[1005];
double w[1005];
vector<ll> G[1005];
double dp[1005][2][2];

void dfs(int v)
{
	for(auto u : G[v]) dfs(u);
	
	double sum[2][2] = {};
	for(auto u : G[v]){
		rep(i, 0, 1) rep(j, 0, 1) sum[i][j] +=  dp[u][i][j];
	}
	
	if(v == n+1){
		rep(i, 0, 1) rep(j, 0, 1) dp[v][i][j] = sum[i][j];
		return;
	}
	rep(i, 0, 1) rep(j, 0, 1){
		double ci = w[v], cj = w[v];
		if(i == 0) ci = -w[v];
		if(j == 0) cj = -w[v];
		dp[v][i][j] = max(sum[1-i][j] + ci, sum[i][1-j] + cj);
	}
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> x[i] >> y[i] >> r[i];
	rep(i, 1, n) w[i] = PI * r[i] * r[i];
	
	SCC scc(n+1); ll S = n+1;
	rep(i, 1, n) rep(j, 1, n){
		if(r[i] <= r[j]) continue;
		ll d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
		if(d <= (r[i]-r[j])*(r[i]-r[j])) scc.add_edge(i, j);
	}
	rep(i, 1, n) scc.add_edge(S, i);
	scc.tpsort();
	
	rep(i, 1, n) dist[i] = -inf;
	for(auto v : scc.topo){
		for(auto u : scc.G[v]){
			chmax(dist[u], dist[v] + 1);
		}
	}
	rep(i, 1, n+1) for(auto v : scc.G[i]) if(dist[v] == dist[i]+1) G[i].push_back(v);
	
	dfs(S);
	printf("%.11f\n", dp[S][1][1]);
	
	return 0;
}