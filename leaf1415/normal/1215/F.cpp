#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, p, M, m;
vector<llint> G[1600005], revG[1600005];
vector<int> topo;
bool used[1600005];
int scc[1600005];

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
	
	cin >> n >> p >> M >> m;
	llint x, y;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		G[p+x].push_back(y);
		G[p+y].push_back(x);
	}
	llint l, r;
	for(int i = 1; i <= p; i++){
		cin >> l >> r;
		G[i].push_back(2*p+l);
		G[i].push_back(2*p+M+r+1);
		G[2*p+M+l].push_back(p+i);
		G[2*p+r+1].push_back(p+i);
	}
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(p+v);
		G[v].push_back(p+u);
	}
	
	for(int i = 1; i < M; i++){
		G[2*p+i+1].push_back(2*p+i);
		G[2*p+M+i].push_back(2*p+M+i+1);
	}
	
	int V = 2*p+2*M;
	for(int i = 1; i <= V; i++){
		for(int j = 0; j < G[i].size(); j++){
			revG[G[i][j]].push_back(i);
		}
	}
	
	for(int i = 1; i <= V; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	int id = 0;
	for(int i = 1; i <= V; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], id++);
	
	for(int i = 1; i <= p; i++){
		if(scc[i] == scc[p+i]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= M; i++){
		if(scc[2*p+i] == scc[2*p+M+i]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	vector<llint> ans;
	for(int i = 1; i <= p; i++){
		if(scc[i] > scc[p+i]) ans.push_back(i);
	}
	llint f = 0;
	for(int i = 1; i <= M; i++){
		if(scc[2*p+i] > scc[2*p+M+i]) f = i;
	}
	cout << ans.size() << " " << f << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}