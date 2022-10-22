#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
vector<P> G[5005];
vector<int> topo;
bool used[5005];
llint ans[5005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i].first]) tpsort(G[v][i].first);
	}
	topo.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(make_pair(v, i));
	}
	
	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	int k = 1;
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++){
		int v = topo[i];
		used[v] = true;
		for(int j = 0; j < G[v].size(); j++){
			int u = G[v][j].first;
			if(used[u]) k = 2, ans[G[v][j].second] = 2;
			else ans[G[v][j].second] =1;
		}
	}
	
	cout << k << endl;
	for(int i = 0; i < m; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}