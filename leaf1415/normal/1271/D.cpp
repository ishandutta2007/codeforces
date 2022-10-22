#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e9

using namespace std;
typedef pair<int, int> P;

int n, m, k;
int dp[10005][5005];
int a[5005], b[5005], c[5005];
int p[5005];
vector<int> vec[5005];
vector<P> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for(int i = 1; i <= n; i++) p[i] = i;
	
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		p[v] = max(p[v], u);
	}
	for(int i = 1; i <= n; i++) vec[p[i]].push_back(i);
	
	for(int i = 1; i <= n; i++){
		pvec.push_back(P(0, i));
		for(int j = 0; j < vec[i].size(); j++){
			pvec.push_back(P(1, vec[i][j]));
		}
	}
	
	int N = pvec.size();
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= 5000; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][k] = 0;
	
	for(int i = 0; i < N; i++){
		llint cid = pvec[i].second;
		for(int j = 0; j <= 5000; j++){
			if(pvec[i].first == 0){
				if(j < a[cid]) continue;
				if(j+b[cid] <= 5000) dp[i+1][j+b[cid]] = max(dp[i+1][j+b[cid]], dp[i][j]);
			}
			else{
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				if(j >= 1) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + c[cid]);
			}
		}
	}
	
	int ans = -inf;
	for(int j = 0; j <= 5000; j++) ans = max(ans, dp[N][j]);
	if(ans < 0) ans = -1;
	cout << ans << endl;
	
	return 0;
}