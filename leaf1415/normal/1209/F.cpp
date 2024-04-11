#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define llint long long
#define mod 1000000007
#define inf 2000000000

using namespace std;

struct edge{
	int to, cost;
	edge(){}
	edge(int a, int b){
		to = a, cost = b;
	}
};

int n, m;
vector<edge> G[600005];
llint dist[600005];
vector<llint> vec[600005][10];
llint ans[600005];

void link(int u, int v, int id)
{
	vector<int> vec;
	for(int x = id; x; x/=10) vec.push_back(x%10);
	reverse(vec.begin(), vec.end());
	int k = vec.size();
	
	vector<int> vec2;
	vec2.push_back(u);
	for(int i = 1; i <= k-1; i++) vec2.push_back(n+i);
	vec2.push_back(v);
	
	for(int i = 1; i <= k; i++) G[vec2[i-1]].push_back(edge(vec2[i], vec[i-1]));
	for(int i = 1; i <= k; i++) G[vec2[k-i+1]].push_back(edge(vec2[k-i], vec[i-1]));
	n += k-1;
}

void bfs()
{
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[1] = 0;
	queue<int> Q;
	Q.push(1);
	
	int v;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i].to;
			if(dist[u] < inf) continue;
			dist[u] = dist[v] + 1;
			Q.push(u);
		}
	}
}

void dfs()
{
	for(int i = 1; i <= n; i++) ans[i] = inf;
	ans[1] = 0;
	
	stack<pair<int, vector<int> > > stk;
	stk.push(make_pair(0, vector<int>()));
	stk.top().second.push_back(1);
	
	while(stk.size()){
		if(stk.top().first == 10){
			stk.pop();
			continue;
		}
		vector<int> &tmp = stk.top().second;
		int x = stk.top().first++;
		stk.push(make_pair(0, vector<int>()));
		
		for(int i = 0; i < tmp.size(); i++){
			int v = tmp[i];
			for(int j = 0; j < vec[v][x].size(); j++){
				int u = vec[v][x][j];
				if(ans[u] < inf) continue;
				ans[u] = ans[v] * 10 + x, ans[u] %= mod;
				stk.top().second.push_back(u);
			}
		}
		if(stk.top().second.size() == 0) stk.pop();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int N = n, u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		link(u, v, i);
	}
	
	bfs();
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(dist[i] + 1 != dist[G[i][j].to]) continue;
			vec[i][G[i][j].cost].push_back(G[i][j].to);
		}
	}
	
	dfs();
	
	for(int i = 2; i <= N; i++) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}