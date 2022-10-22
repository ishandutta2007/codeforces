#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b)
	{
		to = a, cost = b;
	}
};

llint Q;
llint n, k;
vector<edge> G[500005];
llint dp[500005][2];

void dfs(int v, int p)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		dfs(G[v][i].to, v);
	}
	vector<llint> vec;
	llint base = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		base += dp[G[v][i].to][0];
		vec.push_back(dp[G[v][i].to][1] + G[v][i].cost - dp[G[v][i].to][0]);
	}
	sort(vec.rbegin(), vec.rend());
	
	//cout << v << " : "
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	llint sum = base;
	for(int i = 0; i < min(k-1, (llint)vec.size()); i++){
		if(vec[i] > 0) sum += vec[i];
	}
	dp[v][1] = sum;
	
	
	dp[v][0] = 0, sum = base;
	if(vec.size() >= k){
		for(int i = 0; i < k; i++) sum += vec[i];
		dp[v][0] = sum;
	}
	dp[v][0] = max(dp[v][0], dp[v][1]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> k;
		llint u, v, w;
		for(int i = 1; i <= n; i++) G[i].clear();
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v >> w;
			G[u].push_back(edge(v, w));
			G[v].push_back(edge(u, w));
		}
		
		dfs(1, -1);
		
		/*for(int i = 1; i <= n; i++){
			cout << dp[i][0] << " " << dp[i][1] << endl;
		}*/
		
		cout << max(dp[1][0], dp[1][1]) << "\n";
	}
	flush(cout);
	
	return 0;
}