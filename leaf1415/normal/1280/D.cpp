#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m;
llint b[3005], w[3005];
vector<llint> G[3005];
llint num[3005];
P dp[3005][3005], dp2[3005][3005];

void dfs(llint v, llint p)
{
	num[v] = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
		num[v] += num[G[v][i]];
	}
	
	for(int i = 0; i <= G[v].size(); i++){
		for(int j = 0; j <= num[v]; j++){
			dp2[i][j] = P(-inf, -inf);
		}
	}
	dp2[0][0] = P(0LL, w[v]-b[v]);
	
	llint sum = 0;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i];
		if(G[v][i] == p){
			for(int j = 0; j <= sum; j++) dp2[i+1][j] = dp2[i][j];
			continue;
		}
		for(int j = 0; j <= sum; j++){
			for(int k = 0; k <= num[u]; k++){
				P p = dp2[i][j];
				p.first += dp[u][k].first;
				if(dp[u][k].second > 0) p.first++;
				if(j+k+1 <= sum+num[u]) dp2[i+1][j+k+1] = max(dp2[i+1][j+k+1], p);
				
				p = dp2[i][j];
				p.first += dp[u][k].first;
				p.second += dp[u][k].second;
				if(j+k <= sum+num[u]) dp2[i+1][j+k] = max(dp2[i+1][j+k], p);
			}
		}
		sum += num[u];
	}
	for(int j = 0; j <= num[v]; j++) dp[v][j] = dp2[(int)G[v].size()][j];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> b[i];
		for(int i = 1; i <= n; i++) cin >> w[i];
		
		for(int i = 1; i <= n; i++) G[i].clear();
		llint u, v;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, -1);
		
		/*for(int i = 1; i <= n; i++){
			for(int j = 0; j <= m; j++){
				cout << "(" << dp[i][j].first << ", " << dp[i][j].second << ")" << " ";
			}
			cout << endl;
		}*/
		
		llint ans = dp[1][m-1].first;
		if(dp[1][m-1].second > 0) ans++;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}