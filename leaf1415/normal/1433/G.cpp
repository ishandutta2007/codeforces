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
#define pback push_back
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};


llint n, m, K;
vector<edge> G[1005];
llint a[1005], b[1005];
llint dist[1005][1005];


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
	
	cin >> n >> m >> K;
	llint u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		G[u].pback(edge(v, w));
		G[v].pback(edge(u, w));
	}
	rep(i, 1, K) cin >> a[i] >> b[i];
	
	rep(i, 1, n) dijkstra(G, i, dist[i]);
	
	llint ans = inf;
	rep(i, 1, n){
		rep(j, 0, (int)G[i].size()-1){
			llint v = G[i][j].to, sum = 0;
			rep(k, 1, K){
				sum += min(dist[a[k]][b[k]], min(dist[a[k]][i] + dist[v][b[k]], dist[a[k]][v] + dist[i][b[k]]));
			}
			chmin(ans, sum);
		}
	}
	cout << ans << endl;
	
	return 0;
}