#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
vector<llint> G[3005];
llint parent[3005][3005], sum[3005][3005];
llint memo[3005][3005];

llint dfs(llint v, llint p, llint r)
{
	parent[r][v] = p;
	llint ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		ret += dfs(G[v][i], v, r);
	}
	return sum[r][v] = ret;
}

llint calc(llint s, llint t)
{
	if(memo[s][t] != -1) return memo[s][t];
	
	llint ret = 0, ps = parent[t][s], pt = parent[s][t];
	//cout << s << " " << t << " " << ps << " " << pt << endl;
	for(int i = 0; i < G[s].size(); i++){
		int v = G[s][i];
		if(v == ps) continue;
		ret = max(ret, calc(v, t) + sum[s][v] * sum[pt][t]);
	}
	for(int i = 0; i < G[t].size(); i++){
		int v = G[t][i];
		if(v == pt) continue;
		ret = max(ret, calc(s, v) + sum[ps][s] * sum[t][v]);
	}
	return memo[s][t] = ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) dfs(i, 0, i);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			memo[i][j] = -1;
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(i > G[i][j]) continue;
			ans = max(ans, calc(i, G[i][j]) + sum[i][G[i][j]] * sum[G[i][j]][i]);
		}
	}
	cout << ans << endl;
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << calc(i, j) << " ";
		}
		cout << endl;
	}*/
	
	return 0;
}