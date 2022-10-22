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
#define mod 998244353

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

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

ll n, m;
int grundy[100005], gcnt[1<<9];
const ll N = 1<<9;
ll mat[N+10][N+10];
ll ninv;

void swap(int i, int j)
{
	for(int k = 0; k <= N; k++){
		ll t = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = t;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	SCC scc(n);
	int u, v;
	rep(i, 1, m){
		cin >> u >> v;
		scc.add_edge(u, v);
	}
	scc.tpsort();
	
	vector<int> topo = scc.topo;
	reverse(all(topo));
	for(auto v : topo){
		set<int> S;
		for(auto u : scc.G[v]) S.insert(grundy[u]);
		while(S.count(grundy[v])) grundy[v]++;
	}
	rep(i, 1, n) gcnt[grundy[i]]++;
	
	//rep(i, 1, n) cout << grundy[i] << " "; cout << endl;
	//rep(i, 0, N-1) cout << gcnt[i] << " "; cout << endl;
	
	
	ninv = modpow(n+1, mod-2);
	rep(i, 0, N-1){
		mat[i][i] = 1;
		rep(j, 0, N-1){
			mat[i][i^j] += mod - gcnt[j] * ninv % mod;
			mat[i][i^j] %= mod;
		}
		if(i) mat[i][N] = ninv;
	}
	
	/*rep(i, 0, N-1){
		rep(j, 0, N){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/
	
	for(int i = 0; i < N; i++){
		ll max_val = 0; int max_j;
		for(int j = i; j < N; j++){
			if(mat[j][i] > max_val){
				max_val = mat[j][i];
				max_j = j;
			}
		}
		assert(max_val);
		swap(i, max_j);
		
		ll div = mat[i][i];
		for(int j = 0; j <= N; j++){
			mat[i][j] *= modpow(div, mod-2);
			mat[i][j] %= mod;
		}
		for(int j = 0; j < N; j++){
			ll coe = mat[j][i];
			if(i == j) continue;
			for(int k = 0; k <= N; k++){
				mat[j][k] += mod - coe * mat[i][k] % mod;
				if(mat[j][k] >= mod) mat[j][k] -= mod;
			}
		}
	}
	
	/*rep(i, 0, N-1){
		rep(j, 0, N){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << mat[0][N] << endl;
	
	return 0;
}