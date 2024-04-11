#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> l(n);
	for(int i = 0; i < n; i++){
		cin >> l[i];
		l[i]--;
	}
	vector<int> cost(n);
	for(int i = 0; i < n; i++) cin >> cost[i];
	vector<int> prof(n+m, 0);
	for(int i = 0; i < n+m; i++) cin >> prof[i];
	reverse(l.begin(), l.end());
	reverse(cost.begin(), cost.end());
	vector<vector<int> > bestdp(n+m, vector<int>(n+1, -1e9));
	vector<vector<int> > dp(n, vector<int>(n+1, -1e9));
	for(int i = 0; i < n+m; i++) bestdp[i][0] = 0;
	const int B = 20;
	for(int i = 0; i < n; i++){
		dp[i] = bestdp[l[i]];
		for(int j = 1; j <= n; j++){
			int gain = 0;
			int r = __builtin_ctz(j);
			for(int f = 0; f <= r; f++) gain += prof[l[i] + f];
			dp[i][j] = max(dp[i][j], gain - cost[i] + bestdp[l[i]][j-1]);
		}
		bestdp[l[i]] = dp[i];
		for(int z = l[i]; z + 1 < n+m && z < l[i] + B; z++){
			for(int j = 0; j <= n; j++){
				bestdp[z+1][j/2] = max(bestdp[z+1][j/2], bestdp[z][j]);
			}
		}
		for(int z = l[i]; z+1 < n+m; z++){
			bestdp[z+1][0] = max(bestdp[z+1][0], bestdp[z][0]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n+m; i++) for(int j = 0; j <= n; j++) ans = max(ans, bestdp[i][j]);
	cout << ans << '\n';
}