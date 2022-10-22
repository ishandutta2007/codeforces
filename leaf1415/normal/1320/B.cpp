#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, k;
llint p[200005];
vector<edge> G[200005], revG[200005];
llint dist[200005];

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push( make_pair(dist[G[v][i].to], G[v][i].to) );
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(edge(v, 1));
		revG[v].push_back(edge(u, 1));
	}
	cin >> k;
	for(int i = 1; i <= k; i++) cin >> p[i];
	
	dijkstra(revG, p[k], dist);
	
	llint min_ans = 0, max_ans = 0;
	for(int i = 1; i < k; i++){
		int v = p[i]; bool oflag = false, eflag = false;
		for(int j = 0; j < G[v].size(); j++){
			int u = G[v][j].to;
			if(dist[u] + G[v][j].cost == dist[v] && u == p[i+1]) eflag = true;
			if(dist[u] + G[v][j].cost == dist[v] && u != p[i+1]) oflag = true;
		}
		if(!eflag) min_ans++;
		if(!eflag || (eflag && oflag)) max_ans++;
	}
	cout << min_ans << " " << max_ans << endl;
	
	return 0;
}