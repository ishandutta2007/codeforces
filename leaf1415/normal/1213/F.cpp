#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n, k;
llint p[200005], q[200005];
vector<llint> G[200005], revG[200005];

vector<int> topo;
bool used[200005];
int scc[200005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

void sccdfs(int v, int id)
{
	used[v] = true;
	scc[v] = id;
	for(int i = 0; i < revG[v].size(); i++){
		if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) cin >> q[i];
	
	for(int i = 2; i <= n; i++){
		G[p[i-1]].push_back(p[i]);
		revG[p[i]].push_back(p[i-1]);
		G[q[i-1]].push_back(q[i]);
		revG[q[i]].push_back(q[i-1]);
	}
	
	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	int id = 0;
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], id++);
	
	if(id < k){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++){
		cout << (char)(min(scc[i], 25)+'a');
	}
	cout << endl;
	
	return 0;
}