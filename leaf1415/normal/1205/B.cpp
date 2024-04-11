#include <iostream>
#include <vector>
#include <queue>
#define llint long long
#define inf 1000000000

using namespace std;

llint n;
llint a[100005];
vector<llint> vec[65], G[100005];
llint dist[100005];

void bfs(llint s, llint f)
{
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[s] = 0;
	
	queue<llint> Q;
	Q.push(s);
	llint v;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(v == s && G[v][i] == f || v == f && G[v][i] == s) continue;
			if(dist[G[v][i]] < inf) continue;
			dist[G[v][i]] = dist[v] + 1;
			Q.push(G[v][i]);
		}
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 62; j++){
			if(a[i] & (1LL<<j)) vec[j].push_back(i);
		}
	}
	for(int i = 0; i < 62; i++){
		if(vec[i].size() >= 3){
			cout << 3 << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < 62; i++){
		if(vec[i].size() <= 1) continue;
		int u = vec[i][0], v = vec[i][1];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	llint ans = inf;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			int v = G[i][j];
			bfs(i, v);
			ans = min(ans, dist[v]+1);
		}
	}
	if(ans >= inf) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}