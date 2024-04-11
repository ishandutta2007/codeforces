#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define llint long long
#define inf ((llint)1e18)

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m;
llint S;
vector<edge> G[200005];
llint dist[200005];

void dijkstra()
{
	for(int i = 1; i <= n; i++) dist[i] = inf;
	priority_queue<P, vector<P>, greater<P> > Q;
	Q.push(make_pair(0, S));
	dist[S] = 0;
	
	llint v, d;
	while(Q.size()){
		v = Q.top().second;
		d = Q.top().first;
		Q.pop();
		if(d > dist[v]) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push(make_pair(dist[G[v][i].to], G[v][i].to));
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	llint u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w*2));
		G[v].push_back(edge(u, w*2));
	}
	S = n+1;
	llint a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		G[i].push_back(edge(S, a));
		G[S].push_back(edge(i, a));
	}
	
	dijkstra();
	
	for(int i = 1; i <= n; i++){
		cout << dist[i];
		if(i != n) cout << " ";
	}
	cout << endl;
	return 0;
}