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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct edge{
	int to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

ll n, m;
vector<edge> G[100005];
ll dist[5500005];

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 0; i <= 51*n; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		ll w = (v-1)/n; v = (v-1)%n+1;
		if(w == 0){
			for(int i = 0; i < G[v].size(); i++){
				ll u = G[v][i].to + n * G[v][i].cost;
				if(dist[u] > d){
					dist[u] = d;
					Q.push(make_pair(dist[u], u) );
				}
			}
		}
		else{
			for(int i = 0; i < G[v].size(); i++){
				ll u = G[v][i].to, c = (w+G[v][i].cost)*(w+G[v][i].cost);
				if(dist[u] > d + c){
					dist[u] = d + c;
					Q.push(make_pair(dist[u], u) );
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	dijkstra(G, 1, dist);
	
	rep(i, 1, n){
		if(dist[i] > inf/2) cout << -1 << " ";
		else cout << dist[i] << " ";
	}
	cout << endl;
	
	return 0;
}