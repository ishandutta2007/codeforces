#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair< pair<llint, llint>, llint> env;

llint n, m, k;
llint s[100005], t[100005], d[100005], w[100005];
priority_queue<env> Q;
vector<int> vec[100005];
llint D[100005], W[100005];
llint dp[100005][205];

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> s[i] >> t[i] >> d[i] >> w[i];
		vec[s[i]].push_back(i);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < vec[i].size(); j++){
			Q.push(make_pair(make_pair(w[vec[i][j]], d[vec[i][j]]), vec[i][j]));
		}
		while(1){
			if(Q.size() == 0){
				D[i] = i, W[i] = 0;
				break;
			}
			int id = Q.top().second;
			if(t[id] < i){
				Q.pop();
				continue;
			}
			
			D[i] = d[id], W[i] = w[id];
			break;
		}
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= m; j++){
			dp[D[i+1]][j] = min(dp[D[i+1]][j], dp[i][j] + W[i+1]);
			if(j < m) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
		}
	}
	
	llint ans = inf;
	for(int i = 0; i <= m; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}