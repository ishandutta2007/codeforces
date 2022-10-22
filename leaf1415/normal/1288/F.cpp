#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#define mod 1000000007
#define inf 1e10
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cap, cost, rev, id;
	edge(){}
	edge(llint a, llint b, llint c, llint d, llint e){
		to = a, cap = b, cost = c, rev = d, id = e;
	}
};

llint n1, n2, m, r, b;
char c[405], ansc[405];
llint S, T;
vector<P> g[405];
vector<edge> G[405];
llint dist[405];
llint prevv[405], preve[405];

void BellmanFord()
{
	for(llint i = 1; i <= T; i++) dist[i] = inf;
	dist[S] = 0, prevv[S] = -1;
	
	bool update = true;
	while(update){
		update = false;
		for(llint i = 1; i <= T; i++){
			for(llint j = 0; j < G[i].size(); j++){
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

void add_edge(llint from, llint to, llint cap, llint cost, llint id)
{
	G[from].push_back( edge(to, cap, cost, G[to].size(), id) );
	G[to].push_back( edge(from, 0, -cost, G[from].size()-1, -1) );
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n1 >> n2 >> m >> r >> b;
	for(llint i = 1; i <= n1; i++) cin >> c[i];
	for(llint i = 1; i <= n2; i++) cin >> c[n1+i];
	llint u, v;
	for(llint i = 1; i <= m; i++){
		cin >> u >> v;
		v += n1;
		g[u].push_back(P(v, i));
		g[v].push_back(P(u, i));
	}
	
	llint V = n1+n2, M = 1000000, ans = 0;
	S = V+1, T = V+2;
	for(llint i = 1; i <= V; i++)
	{
		if(c[i] == 'U') add_edge(S, i, inf, 0, -1), add_edge(i, T, inf, 0, -1);
		if((i <= n1 && c[i] == 'R') || (i > n1 && c[i] == 'B')){
			add_edge(S, i, inf, 0, -1);
			add_edge(S, i, 1, -M, -1);
			ans += M;
		}
		if((i <= n1 && c[i] == 'B') || (i > n1 && c[i] == 'R')){
			add_edge(i, T, inf, 0, -1);
			add_edge(i, T, 1, -M, -1);
			ans += M;
		}
		for(llint j = 0; j < g[i].size(); j++) add_edge(i, g[i][j].first, 1, (i<=n1)?r:b, g[i][j].second);
	}
	
	/*for(int i = 1; i <= V; i++){
		for(int j = 0; j < G[i].size(); j++) cout << G[i][j].to << " "; cout << endl;
	}*/
	
	llint f = inf;
	while(f > 0){
		BellmanFord();
		if(dist[T] >= 0) break;
		llint p = T, flow = f;
		while(prevv[p] != -1){
			flow = min(flow, G[prevv[p]][preve[p]].cap);
			p = prevv[p];
		}
		p = T;
		while(prevv[p] != -1){
			G[prevv[p]][preve[p]].cap -= flow;
			G[p][G[prevv[p]][preve[p]].rev].cap += flow;
			p = prevv[p];
		}
		f -= flow;
		ans += dist[T] * flow;
	}
	
	for(int i = 1; i <= T; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(G[i][j].cost <= -M && G[i][j].cap > 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	cout << ans << endl;
	for(llint i = 1; i <= m; i++) ansc[i] = 'U';
	for(llint i = 1; i <= V; i++){
		for(llint j = 0; j < G[i].size(); j++){
			if(G[i][j].id == -1) continue;
			if(G[i][j].cap == 0){
				if(i <= n1) ansc[G[i][j].id] = 'R';
				else ansc[G[i][j].id] = 'B';
			}
		}
	}
	
	for(llint i = 1; i <= m; i++)  cout << ansc[i]; cout << endl;
	
	return 0;
}