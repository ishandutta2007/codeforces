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

ll n, m, k;
string s[100005], t[100005];
ll x[100005];
map<string, ll> mp;
vector<ll> vec[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	rep(i, 1, n) cin >> s[i], mp[s[i]] = i;
	rep(i, 1, m) cin >> t[i] >> x[i];
	
	ll K = 1<<k;
	rep(i, 1, m){
		rep(j, 0, K-1){
			string u = t[i];
			rep(l, 0, k-1) if(j & (1<<l)) u[l] = '_';
			if(mp.count(u)) vec[i].push_back(mp[u]);
		}
	}
	
	SCC scc(n);
	rep(i, 1, m){
		bool flag = false;
		for(auto v : vec[i]){
			if(v == x[i]) flag = true;
			else scc.add_edge(x[i], v);
		}
		if(!flag){
			cout << "NO" << endl;
			return 0;
		}
	}
	scc.tpsort();
	if(!scc.checkDAG()){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	rep(i, 1, n) cout << scc.topo[i-1] << " "; cout << endl;
	
	return 0;
}