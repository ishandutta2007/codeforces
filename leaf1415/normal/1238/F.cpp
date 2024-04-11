#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint Q, n;
vector<llint> G[600005];
llint w[600005];
llint dist[600005];

void dfs(llint v, llint p, llint d)
{
	dist[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v, d+w[v]+w[G[v][i]]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= 2*n; i++) G[i].clear();
		llint u, v;
		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 1; i <= n; i++){
			w[i] = 1;
			if(G[i].size() > 1) w[i] += (int)G[i].size()-2;
		}
		int m = n+1;
		for(int i = 1; i <= n; i++){
			if(G[i].size() == 1){
				G[m].push_back(i);
				G[i].push_back(m);
				m++;
			}
		}
		m--;
		for(int i = n+1; i <= m; i++) w[i] = 0;
		
		dfs(1, -1, 0);
		llint root, diam = -1;
		for(int i = 1; i <= m; i++){
			if(diam < dist[i]){
				diam = dist[i];
				root = i;
			}
		}
		dfs(root, -1, 0);
		diam = -1;
		for(int i = 1; i <= m; i++){
			if(diam < dist[i]){
				diam = dist[i];
				root = i;
			}
		}
		cout << diam/2 << "\n";
	}
	flush(cout);
	
	return 0;
}