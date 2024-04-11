#include <iostream>
#include <string>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b)
	{
		to = a, cost = b;
	}
	
};

llint T;
llint k, n;
vector<edge> G[200005];
llint num[200005];
llint ansG, ansB;

llint dfs(llint v, llint p)
{
	num[v] = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		num[v] += dfs(G[v][i].to, v);
	}
	return num[v];
}

void dfs2(llint v, llint p)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		llint u = G[v][i].to;
		if(num[u] % 2) ansG += G[v][i].cost;
		ansB += min(num[u], n-num[u]) * G[v][i].cost;
		dfs2(u, v);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> k;
		n = 2*k;
		for(int i = 1; i <= n; i++) G[i].clear();
		
		llint u, v, w;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v >> w;
			G[u].push_back(edge(v, w));
			G[v].push_back(edge(u, w));
		}
		dfs(1, -1);
		
		ansG = 0, ansB = 0;
		dfs2(1, -1);
		cout << ansG << " "<< ansB << "\n";
	}
	flush(cout);
	
	return 0;
}