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


struct MinCostFlow{
	struct edge{
		llint to, cap, cost, rev;
		edge(){}
		edge(llint a, llint b, llint c, llint d){
			to = a, cap = b, cost = c, rev = d;
		}
	};
	int n;
	vector<vector<edge> > G;
	vector<llint> dist;
	vector<int> prevv, preve;
	vector<llint> h;
	
	MinCostFlow(){}
	MinCostFlow(int n){
		this->n = n;
		G.resize(n+1);
		dist.resize(n+1);
		prevv.resize(n+1);
		preve.resize(n+1);
		h.resize(n+1);
	}
	void BellmanFord(int s)
	{
		for(int i = 0; i <= n; i++) dist[i] = inf;
		dist[s] = 0, prevv[s] = -1;
		
		bool update = true;
		while(update){
			update = false;
			for(int i = 0; i <= n; i++){
				for(int j = 0; j < G[i].size(); j++){
					if(G[i][j].cap == 0) continue;
					if(dist[G[i][j].to] > dist[i] + G[i][j].cost){
						dist[G[i][j].to] = dist[i] + G[i][j].cost;
						prevv[G[i][j].to] = i;
						preve[G[i][j].to] = j;
						update = true;
					}
				}
			}
		}
	}
	void Dijkstra(int s)
	{
		for(int i = 0; i <= n; i++) dist[i] = inf;
		dist[s] = 0, prevv[s] = -1;
		
		priority_queue< P, vector<P>, greater<P> > Q;
		Q.push( make_pair(0, s) );
		
		llint v, d;
		while(Q.size()){
			d = Q.top().first;
			v = Q.top().second;
			Q.pop();
			if(dist[v] < d) continue;
			for(int i = 0; i < G[v].size(); i++){
				if(G[v][i].cap == 0) continue;
				llint u = G[v][i].to, c = h[v] - h[u] + G[v][i].cost;
				if(dist[u] > d + c){
					dist[u] = d + c;
					prevv[u] = v;
					preve[u] = i;
					Q.push( P(dist[u], u) );
				}
			}
		}
	}
	void add_edge(int from, int to, llint cap, llint cost)
	{
		G[from].push_back( edge(to, cap, cost, G[to].size()) );
		G[to].push_back( edge(from, 0, -cost, G[from].size()-1) );
	}
	llint calc(int s, int t, llint f)
	{
		BellmanFord(s);
		for(int i = 0; i <= n; i++) h[i] = dist[i];
		
		llint ret = 0;
		while(f > 0){
			Dijkstra(s);
			if(dist[t] >= inf) break;
			
			llint p = t, flow = f;
			while(prevv[p] != -1){
				flow = min(flow, G[prevv[p]][preve[p]].cap);
				p = prevv[p];
			}
			
			p = t;
			while(prevv[p] != -1){
				G[prevv[p]][preve[p]].cap -= flow;
				G[p][G[prevv[p]][preve[p]].rev].cap += flow;
				p = prevv[p];
			}
			f -= flow;
			ret += (dist[t] + h[t] - h[s]) * flow;
			
			for(int i = 0; i <= n; i++) h[i] += dist[i]; //(?)
		}
		if(f > 0) return 1;
		return ret;
	}
};

ll n;
ll a[3005];
MinCostFlow mcf(12005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	ll S = 4*n+1, T = 4*n+2;
	rep(i, 1, n){
		mcf.add_edge(S, 2*n+i, 1, 0);
		mcf.add_edge(i, 2*n+i, 1, 0);
		mcf.add_edge(n+i, 2*n+i, 1, 0);
		mcf.add_edge(2*n+i, 3*n+i, 1, -1);
		mcf.add_edge(3*n+i, T, 1, 0);
		
		rep(j, i+1, n){
			if(a[j] == a[i]){
				mcf.add_edge(i, j, 4, 0);
				break;
			}
		}
		rep(j, i+1, n){
			if(a[j]%7 == a[i]%7){
				mcf.add_edge(n+i, n+j, 4, 0);
				mcf.add_edge(3*n+i, n+j, 4, 0);
				break;
			}
		}
		rep(j, i+1, n){
			if(a[j] == a[i]+1){
				mcf.add_edge(3*n+i, j, 1, 0);
				break;
			}
		}
		rep(j, i+1, n){
			if(a[j] == a[i]-1){
				mcf.add_edge(3*n+i, j, 1, 0);
				break;
			}
		}
	}
	cout << -mcf.calc(S, T, 4) << endl;
	
	return 0;
}