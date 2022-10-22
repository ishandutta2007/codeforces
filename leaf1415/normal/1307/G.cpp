#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cassert>
#define llint long long
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> PP;

struct edge{
	int to, cap, cost, rev;
	edge(){}
	edge(int a, int b, int c, int d){
		to = a, cap = b, cost = c, rev = d;
	}
};


int n, m, Q;
int S, T;
vector<edge> G[55];
int dist[55];
int prevv[55], preve[55];
vector<llint> vec;
vector<PP> vec2;

void BellmanFord()
{
	for(int i = 1; i <= T; i++) dist[i] = inf;
	dist[S] = 0, prevv[S] = -1;
	
	bool update = true;
	while(update){
		update = false;
		for(int i = 1; i <= T; i++){
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

void add_edge(int from, int to, int cap, int cost)
{
	G[from].push_back( edge(to, cap, cost, G[to].size()) );
	G[to].push_back( edge(from, 0, -cost, G[from].size()-1) );
}

double calc(double x)
{
	llint p = upper_bound(vec2.begin(), vec2.end(), PP(x, P(inf, inf))) - vec2.begin() - 1;
	if(p < 0) return 0;
	return vec2[p].second.second + vec2[p].second.first * (x - vec2[p].first);
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	llint u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		add_edge(u, v, 1, w);
	}
	S = 1, T = n;
	
	while(1){
		BellmanFord();
		if(dist[T] > inf/2) break;
		vec.push_back(dist[T]);
		
		int p = T, flow = inf;
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
	}
	
	llint pre = vec.front(), sum = 0, add = 0;
	for(llint i = 0; i < vec.size(); i++){
		if(vec[i] > pre){
			sum += add, add = 0;
			vec2.push_back(PP(pre, P(i, sum)));
			sum += i*(vec[i]-pre);
			pre = vec[i];
		}
		else add += pre - vec[i];
	}
	sum += add;
	vec2.push_back(PP(pre, P((int)vec.size(), sum)));
	
	cin >> Q;
	llint x;
	for(int q = 0; q < Q; q++){
		cin >> x;
		
		double ub = 1e9, lb = vec.front(), mid;
		for(int i = 0; i < 100; i++){
			mid = (ub+lb)/2;
			if(calc(mid) <= x) lb = mid;
			else ub = mid;
		}
		printf("%.11f\n", lb);
	}
	flush(cout);
	
	return 0;
	
}