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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

ll n, m;
vector<edge> G[1000005];
ll dist[1000005];

void add_edge(ll u, ll v, ll w)
{
	rep(i, 0, 3){
		rep(j, 0, 3){
			if((i & j) != i) continue;
			int f = i*n+u, t = j*n+v;
			ll c = w;
			if((i & 1) == 0 && (j & 1)) c += w;
			if((i & 2) == 0 && (j & 2)) c -= w;
			G[f].push_back(edge(t, c));
		}
	}
}

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 1; i <= 4*n; i++) dist[i] = inf;
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
	ll u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	
	dijkstra(G, 1, dist);
	
	rep(i, 2, n) cout << dist[3*n+i] << " "; cout << endl;
	
	return 0;
}