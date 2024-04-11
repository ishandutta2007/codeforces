#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
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

llint n;
llint a[200005];
vector<edge> G[200005];
llint O, E;
llint distO[200005], distE[200005];

void dijkstra(llint dist[], llint S)
{
	for(int i = 1; i <= E; i++) dist[i] = inf;
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
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	O = n+1, E = n+2;
	for(int i = 1; i <= n; i++){
		if(a[i]%2) G[O].push_back(edge(i, 0));
		else G[E].push_back(edge(i, 0));
	}
	for(int i = 1; i <= n; i++){
		if(i+a[i] <= n) G[i+a[i]].push_back(edge(i, 1));
		if(i-a[i] >= 1) G[i-a[i]].push_back(edge(i, 1));
	}
	
	dijkstra(distO, O);
	dijkstra(distE, E);
	
	llint ans;
	for(int i = 1; i <= n; i++){
		if(a[i]%2) ans = distE[i];
		else ans = distO[i];
		if(ans >= inf/2) ans = -1;
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}