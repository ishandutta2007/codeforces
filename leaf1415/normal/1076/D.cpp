#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost, id;
	edge(){}
	edge(llint a, llint b, llint c){
		to = a, cost = b, id = c;
	}
};

llint n, m, k;
vector<edge> G[300005];
llint dist[300005];
bool used[300005];
vector<llint> ans;

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

void dfs(int v)
{
	used[v] = true;
	for(auto e : G[v]){
		llint u = e.to;
		if(used[u]) continue;
		if(dist[v] + e.cost != dist[u]) continue;
		if(ans.size() >= k) continue;
		ans.push_back(e.id);
		dfs(u);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	llint u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w, i));
		G[v].push_back(edge(u, w, i));
	}
	dijkstra(G, 1, dist);
	
	k = min(k, n-1);
	dfs(1);
	
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}