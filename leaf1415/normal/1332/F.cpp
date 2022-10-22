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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n;
vector<llint> G[300005];
llint dp[300005][2][2];
llint dp2[300005][2][2];

void dfs(int v, int p)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	llint d = G[v].size();
	for(int i = 0; i <= d; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				dp2[i][j][k] = 0;
			}
		}
	}
	dp2[0][0][0] = 1;
	
	for(int i = 0; i < d; i++){
		llint u = G[v][i];
		if(u == p){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					dp2[i+1][j][k] = dp2[i][j][k];
				}
			}
			continue;
		}
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 2; l++){
					for(int m = 0; m < 2; m++){
						if(l == 0 || m == 1) (dp2[i+1][j][k] += dp[u][l][m] * dp2[i][j][k] % mod) %= mod;
						(dp2[i+1][j|l][1] += dp[u][l][m] * dp2[i][j][k] % mod) %= mod;
					}
				}
			}
		}
	}
	for(int k = 0; k < 2; k++){
		dp[v][0][k] = (dp2[d][0][k] + dp2[d][1][k]) % mod;
		dp[v][1][k] = dp2[d][0][k];
	}
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
	
	dfs(1, -1);
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++){
			cout << dp[i][j/2][j%2] << " ";
		}
		cout << endl;
	}*/
	
	llint ans = dp[1][0][0] + dp[1][0][1] + dp[1][1][1]; ans %= mod;
	ans += mod - 1, ans %= mod;
	cout << ans << endl;
	
	return 0;
}