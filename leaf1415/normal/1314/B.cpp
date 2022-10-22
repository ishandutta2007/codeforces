#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint n, k, N;
llint a[1<<17];
llint cnt2[1<<16], cnt4[1<<15];
llint dp[1<<17][4];

void dfs(int v)
{
	if(v >= N) return;
	for(int i = 0; i < 2; i++) dfs(v*2+i);
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			llint k = i | j;
			dp[v][k] = max(dp[v][k], dp[v*2][i] + dp[v*2+1][j] + k);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < k; i++) cin >> a[i], a[i]--;
	
	if(k == 0){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 1;
	for(int i = 0; i < k; i++){
		cnt2[a[i]/2]++;
		cnt4[a[i]/4]++;
	}
	for(int i = 0; i < (1<<(n-1)); i++){
		if(cnt2[i]) ans++;
	}
	
	N = 1<<(n-2);
	for(int i = 0; i < 2*N; i++){
		for(int j = 0; j < 4; j++){
			dp[i][j] = -inf;
		}
	}
	for(int i = 0; i < N; i++){
		dp[N+i][0] = 0;
		if(cnt4[i] >= 1){
			dp[N+i][2] = 2;
			dp[N+i][1] = 1;
		}
		if(cnt4[i] >= 2) dp[N+i][3] = 3;
	}
	
	dfs(1);
	
	llint tmp = 0;
	for(int i = 0; i < 4; i++){
		tmp = max(tmp, dp[1][i]);
	}
	ans += tmp;
	
	cout << ans << endl;
	
	return 0;
}