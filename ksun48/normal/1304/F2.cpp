#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > cost(n+1, vector<int>(m, 0));
	vector<vector<int> > psum(n+1, vector<int>(m+1+k, 0));
	for(int i = n; i >= 1; i--){
		psum[i][0] = 0;
		for(int j = 0; j < m; j++){
			cin >> cost[i][j];
			psum[i][j+1] = psum[i][j] + cost[i][j];
		}
		for(int j = m+1; j < (int)psum[i].size(); j++){
			psum[i][j] = psum[i][j-1];
		}
	}
	vector<int> dp(m, 0);
	for(int b = 1; b <= n; b++){
		vector<int> newdp(m, 0);
		int zz = 0;
		for(int i = 0; i < m; i++){
			if(i >= k){
				zz = max(zz, dp[i - k]);
			}
			newdp[i] = max(newdp[i], zz + psum[b][i+k] - psum[b][i] + psum[b-1][i+k] - psum[b-1][i]);
		}
		zz = 0;
		for(int i = m-1; i >= 0; i--){
			if(i + k < m){
				zz = max(zz, dp[i + k]);
			}
			newdp[i] = max(newdp[i], zz + psum[b][i+k] - psum[b][i] + psum[b-1][i+k] - psum[b-1][i]);
		}
		// for(int i = 0; i < m; i++){
		// 	for(int r = i - k; r <= i + k; r++){
		// 		if(r >= 0 && r < m){
		// 			newdp[r] = max(newdp[r], dp[i] + psum[b][r+k] - psum[b][r]
		// 			 + (psum[b-1][max(i,r)+k] - psum[b-1][min(i,r)])
		// 			 - (psum[b-1][i+k] - psum[b-1][i]));
		// 		}
		// 	}
		// }
		multiset<int> f;
		f.insert(-1e9);
		for(int i = 0; i < m; i++){
			f.insert(dp[i] - psum[b-1][i+k]);
			newdp[i] = max(newdp[i], *f.rbegin() + psum[b-1][i+k] + (psum[b][i+k] - psum[b][i]));
			if(i >= k){
				f.erase(f.find(dp[i-k] - psum[b-1][i]));
			}
		}
		f.clear();
		f.insert(-1e9);
		for(int i = m-1; i >= 0; i--){
			f.insert(dp[i] + psum[b-1][i]);
			newdp[i] = max(newdp[i], *f.rbegin() - psum[b-1][i] + (psum[b][i+k] - psum[b][i]));
			if(i + k <= m-1){
				f.erase(f.find(dp[i+k] + psum[b-1][i+k]));
			}
		}
		dp = newdp;
	}
	int best = 0;
	for(int a : dp) best = max(a, best);
	cout << best << '\n';
}