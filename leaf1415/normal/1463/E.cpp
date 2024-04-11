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
	vector<vector<int> > G, revG, g;
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

ll n, k;
ll x[300005], y[300005];
ll in[300005], out[300005];
ll order[300005];
vector<P> vec[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	SCC scc(n);
	ll p;
	rep(i, 1, n){
		cin >> p;
		if(p) scc.add_edge(p, i);
	}
	rep(i, 1, k){
		cin >> x[i] >> y[i];
		scc.add_edge(x[i], y[i]);
		in[y[i]]++, out[x[i]]++;
	}
	rep(i, 1, n){
		if(in[i] >= 2 || out[i] >= 2){
			cout << 0 << endl;
			return 0;
		}
	}
	
	scc.tpsort();
	if(!scc.checkDAG()){
		cout << 0 << endl;
		return 0;
	}
	rep(i, 0, n-1) order[scc.topo[i]] = i;
	
	rep(i, 1, k) scc.add_edge(y[i], x[i]);
	scc.tpsort();
	ll c = scc.calcSCC();
	rep(i, 1, n) vec[scc.scc[i]].push_back(P(order[i], i));
	
	if(c != n - k){
		cout << 0 << endl;
		return 0;
	}
	
	rep(i, 0, c-1){
		sort(all(vec[i]));
		for(auto p : vec[i]) cout << p.second << " ";
	}
	cout << endl;
	
	return 0;
}