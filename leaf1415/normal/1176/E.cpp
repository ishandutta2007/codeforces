#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint T;
llint n, m;
vector<int> G[200005];
int color[200005];
int pcnt, ncnt;

void dfs(int v, int c)
{
	color[v] = c;
	for(int i = 0; i < G[v].size(); i++){
		if(color[G[v][i]]) continue;
		dfs(G[v][i], -c);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++) G[i].clear();
		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		for(int i = 1; i <= n; i++) color[i] = 0;
		dfs(1, 1);
		pcnt = ncnt = 0;
		for(int i = 1; i <= n; i++){
			if(color[i] > 0) pcnt++;
			else ncnt++;
		}
		if(pcnt <= n/2){
			cout << pcnt << endl;
			for(int i = 1; i <= n; i++) if(color[i] > 0) cout << i << " "; cout << "\n";
		}else{
			cout << ncnt << endl;
			for(int i = 1; i <= n; i++) if(color[i] < 0) cout << i << " "; cout << "\n";
		}
	}
	flush(cout);
	
	return 0;
}