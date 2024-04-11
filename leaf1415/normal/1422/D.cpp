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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b)
	{
		to = a, cost = b;
	}
};

llint n, m;
llint S, T;
llint sx, sy, tx, ty;
llint x[100005], y[100005];
vector<P> vecx, vecy;
vector<edge> G[100005];
llint dist[100005];

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 1; i <= T; i++) dist[i] = inf;
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

inline llint calc(llint x, llint y, llint x2, llint y2)
{
	return abs(x-x2)+abs(y-y2);
}
inline llint calc2(llint x, llint y, llint x2, llint y2)
{
	return min(abs(x-x2), abs(y-y2));
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> sx >> sy >> tx >> ty;
	for(int i = 1; i <= m; i++){
		cin >> x[i] >> y[i];
		vecx.push_back(P(x[i], i));
		vecy.push_back(P(y[i], i));
	}
	sort(vecx.begin(), vecx.end());
	sort(vecy.begin(), vecy.end());
	
	S = m+1, T = m+2;
	for(int i = 1; i < vecx.size(); i++){
		llint u = vecx[i-1].second, v = vecx[i].second, d = abs(vecx[i-1].first - vecx[i].first);
		G[u].push_back(edge(v, d));
		G[v].push_back(edge(u, d));
	}
	for(int i = 1; i < vecy.size(); i++){
		llint u = vecy[i-1].second, v = vecy[i].second, d = abs(vecy[i-1].first - vecy[i].first);
		G[u].push_back(edge(v, d));
		G[v].push_back(edge(u, d));
	}
	G[S].push_back(edge(T, calc(sx, sy, tx, ty)));
	G[T].push_back(edge(S, calc(sx, sy, tx, ty)));
	
	for(int i = 1; i <= m; i++){
		G[S].push_back(edge(i, calc2(sx, sy, x[i], y[i])));
		G[i].push_back(edge(S, calc(sx, sy, x[i], y[i])));
		G[T].push_back(edge(i, calc2(tx, ty, x[i], y[i])));
		G[i].push_back(edge(T, calc(tx, ty, x[i], y[i])));
	}
	
	dijkstra(G, S, dist);
	cout << dist[T] << endl;
	
	return 0;
}