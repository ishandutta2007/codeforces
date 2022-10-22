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
#define mod 998244353

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;

struct edge{
	llint to;
	P cost;
	edge(llint a, P b){
		to = a, cost = b;
	}
};

llint n, m;
vector<llint> G[2][200005];
vector<edge> G2[400005];
llint dist[21][200005];
P dist2[400005];
bool used[21][200005];

void bfs01()
{
	deque<P> deq;
	deq.push_back(P(0, 1));
	
	rep(i, 0, 20){
		rep(j, 1, n) dist[i][j] = inf;
	}
	dist[0][1] = 0;
	
	while(deq.size()){
		P p = deq.front();
		llint f = p.first, v = p.second;
		deq.pop_front();
		
		for(int i = 0; i < G[f&1][v].size(); i++){
			int u = G[f&1][v][i];
			if(dist[f][u] > dist[f][v] + 1){
				dist[f][u] = dist[f][v] + 1;
				deq.push_back(P(f, u));
			}
		}
		if(f+1 <= 20){
			if(dist[f+1][v] > dist[f][v]){
				dist[f+1][v] = dist[f][v];
				deq.push_front(P(f+1, v));
			}
		}
	}
}

void dijkstra(vector<edge> G[], llint S, P dist[])
{
	for(int i = 1; i <= 2*n; i++) dist[i] = P(inf, inf);
	dist[S] = P(0, 0);
	
	priority_queue< T, vector<T>, greater<T> > Q;
	Q.push( make_pair(P(0, 0), S) );
	
	llint v;
	P d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			P ncost = P(d.first+G[v][i].cost.first, d.second+G[v][i].cost.second);
			if(dist[G[v][i].to] > ncost){
				dist[G[v][i].to] = ncost;
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
	rep(i, 1, m){
		cin >> u >> v;
		G[0][u].push_back(v);
		G[1][v].push_back(u);
		G2[u].push_back(edge(v, P(0, 1)));
		G2[v+n].push_back(edge(u+n, P(0, 1)));
	}
	rep(i, 1, n){
		G2[i].push_back(edge(n+i, P(1, 0)));
		G2[n+i].push_back(edge(i, P(1, 0)));
	}
	
	llint ans = inf;
	bfs01();
	
	rep(i, 0, 18){
		ans = min(ans, (1<<i)-1+dist[i][n]);
	}
	if(ans < inf/2){
		cout << ans%mod << endl;
		return 0;
	}
	
	dijkstra(G2, 1, dist2);
	P tmp = min(dist2[n], dist2[2*n]);
	
	//cout << tmp.first << " " << tmp.second << endl;
	
	ans = tmp.second;
	llint mul = 1;
	rep(i, 0, tmp.first-1){
		ans += mul, ans %= mod;
		mul *= 2, mul %= mod;
	}
	cout << ans << endl;
	
	return 0;
}