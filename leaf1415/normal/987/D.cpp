#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define inf 1e9

using namespace std;

typedef pair<int, int> P;

struct edge{
	int to, cost;
	edge(int a, int b){
		to = a, cost = b;
	}
};

int n, m, k, s;
int a[100005];
int V;
vector<edge> G[100105];
int dist[105][100005];

vector<int> cost[100005];

void bfs(int S, int dist[])
{
	for(int i = 1; i <= V; i++) dist[i] = inf;
	
	queue<int> Q;
	for(int i = 0; i < G[S].size(); i++){
		dist[G[S][i].to] = 0;
		Q.push(G[S][i].to);
	}
	
	int v;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] < inf) continue;
			dist[G[v][i].to] = dist[v] + 1;
			Q.push(G[v][i].to);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	
	cin >> n >> m >> k >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		G[n+a[i]].push_back(edge(i, 0));
	}
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(edge(v, 1));
		G[v].push_back(edge(u, 1));
	}
	V = n + k;
	
	for(int i = 1; i <= k; i++) bfs(n + i, dist[i]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			cost[i].push_back(dist[j][i]);
		}
		sort(cost[i].begin(), cost[i].end());
	}
	
	for(int i = 1; i <= n; i++){
		int ans = 0;
		for(int j = 0; j < s; j++){
			ans += cost[i][j];
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}