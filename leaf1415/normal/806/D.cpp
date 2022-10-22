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
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};


ll n;
ll a[2005][2005], m[2005];
vector<edge> G[2005];
ll dist[2005], dist2[2005];

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
	
	cin >> n;
	rep(i, 1, n) rep(j, i+1, n){
		cin >> a[i][j];
		a[j][i] = a[i][j];
	}
	
	ll u, v, b = inf;
	rep(i, 1, n) rep(j, 1, n) if(i != j && b > a[i][j]) b = a[i][j], u = i, v = j;
	rep(i, 1, n){
		m[i] = inf;
		rep(j, 1, n) if(i != j) a[i][j] -= b, chmin(m[i], a[i][j]);
	}
	
	rep(i, 1, n) rep(j, 1, n) if(i != j) G[i].push_back(edge(j, a[i][j]));
	rep(i, 1, n) G[u].push_back(edge(i, 2*m[i]));
	
	dijkstra(G, u, dist);
	dijkstra(G, v, dist2);
	
	rep(i, 1, n) cout << min(dist[i], dist2[i]) + (n-1) * b << endl;
	
	return 0;
}