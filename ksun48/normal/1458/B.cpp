#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	const int R = 10001;
	vector<vector<int> > dp(n+1, vector<int>(R+1, -1e8));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		vector<vector<int> > newdp = dp;
		for(int j = 0; j < n; j++){
			for(int z = 0; z <= R; z++){
				if(z + a[i] <= R){
					newdp[j+1][z+a[i]] = max(newdp[j+1][z+a[i]], dp[j][z] + b[i]);
				}
			}
		}
		dp = newdp;
	}
	cout << fixed << setprecision(1);
	int sumb = 0;
	for(int i = 0; i < n; i++) sumb += b[i];
	for(int i = 1; i <= n; i++){
		int best = -1e8;
		for(int r = 0; r <= R; r++){
			best = max(best, min(2 * r, dp[i][r] + sumb));
		}
		double ans = best;
		ans /= 2;
		cout << ans << '\n';
	}
}