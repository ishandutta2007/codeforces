#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint a[205];
vector<llint> G[205];
llint dp[205][205], dpmax[205][205];
llint dp2[205][2];

void dfs(llint v, llint p)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	llint sum = a[v];
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		int u = G[v][i];
		sum += dpmax[u][k-1];
	}
	dp[v][0] = sum;
	
	for(llint i = 1; i <= n; i++){
		for(int j = 0; j <= (int)G[v].size(); j++) dp2[j][0] = dp2[j][1] = -inf;
		dp2[0][0] = 0;
		for(int j = 0; j < G[v].size(); j++){
			if(G[v][j] == p){
				dp2[j+1][0] = dp2[j][0];
				dp2[j+1][1] = dp2[j][1];
				continue;
			}
			int u = G[v][j];
			for(int l = 0; l < 2; l++){
				if(l == 0) dp2[j+1][1] = max(dp2[j+1][1], dp2[j][l] + dp[u][i-1]);
				dp2[j+1][l] = max(dp2[j+1][l], dp2[j][l] + dpmax[u][max(i-1, k-i-1)]);
			}
		}
		dp[v][i] = dp2[(int)G[v].size()][1];
	}
	for(int i = n; i >= 0; i--) dpmax[v][i] = max(dpmax[v][i+1], dp[v][i]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k; k++;
	for(int i = 1; i <= n; i++) cin >> a[i];
	llint u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = -inf;
		}
	}
	
	dfs(1, -1);
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cout << dpmax[1][0] << endl;
	
	return 0;
}