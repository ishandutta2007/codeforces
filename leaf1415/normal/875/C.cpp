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
	SCC(int n){  //V(G) = {1, 2, ..., n}, n
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
		//cout << u << " " << v << endl;
		G[u].push_back(v);
	}
	void tpsort()
	{
		topo.clear();
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 1; i <= n; i++) if(!used[i]) tpdfs(i);
		reverse(topo.begin(), topo.end());
	}
	int calcSCC(){  //tpsort()SCCSCC-ID0-indexed
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
};

ll n, m;
vector<ll> vec[100005];
SCC scc;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll l, x;
	rep(i, 1, n){
		cin >> l;
		rep(j, 1, l){
			cin >> x;
			vec[i].push_back(x);
		}
	}
	scc = SCC(2*m);
	
	rep(i, 1, n-1){
		rep(j, 0, (int)vec[i].size()-1){
			if(j >= vec[i+1].size()){
				cout << "No" << endl;
				return 0;
			}
			if(vec[i][j] != vec[i+1][j]){
				if(vec[i][j] < vec[i+1][j]){
					scc.add_edge(vec[i][j]+m, vec[i+1][j]+m);
					scc.add_edge(vec[i+1][j], vec[i][j]);
				}
				else{
					scc.add_edge(vec[i][j]+m, vec[i][j]);
					scc.add_edge(vec[i+1][j], vec[i+1][j]+m);
				}
				break;
			}
		}
	}
	
	scc.tpsort();
	scc.calcSCC();
	
	//rep(i, 1, 2*m) cout << scc.scc[i] << " "; cout << endl;
	
	vector<ll> ans;
	rep(i, 1, m){
		if(scc.scc[i] == scc.scc[i+m]){
			cout << "No" << endl;
			return 0;
		}
		if(scc.scc[i] > scc.scc[i+m]) ans.push_back(i);
	}
	cout << "Yes" << endl;
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}