#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

struct edge{
	llint to, cap, rev;
	edge(llint a, llint b, llint c){
		to = a, cap = b, rev = c;
	}
};

llint n, m;
llint a[1005];

vector<edge> G[2005];
llint S, T;
bool used[2005];

int dfs(int v, llint f)
{
	used[v] = true;
	if(v == T) return f;
	
	llint ret;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i].to] || G[v][i].cap <= 0) continue;
		ret = dfs(G[v][i].to, min(f, G[v][i].cap));
		if(ret > 0){
			G[v][i].cap -= ret;
			G[G[v][i].to][G[v][i].rev].cap += ret;
			return ret;
		}
	}
	return 0;
}

void add_edge(int s, int t, llint cap)
{
	G[s].push_back(edge(t, cap, G[t].size()));
	G[t].push_back(edge(s, 0, G[s].size()-1));
}


int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	S = n+m+1, T = n+m+2;
	
	llint u, v, w, pos = 0;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		pos += w;
		add_edge(S, n+i, w);
		add_edge(n+i, u, inf);
		add_edge(n+i, v, inf);
	}
	for(int i = 1; i <= n; i++) add_edge(i, T, a[i]);
	
	llint ans = 0, flow;
	while(1){
		for(int i = 1; i <= T; i++) used[i] = false;
		flow = dfs(S, inf);
		if(flow <= 0) break;
		ans += flow;
	}
	cout << pos - ans << endl;
	
	return 0;
}