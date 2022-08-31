#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1e8;
	for(int _ = 0; _ < 4; _++){
		vector<int> dp(n+1, 1e8);
		dp[0] = 0;
		vector<string> ok = {"RL", "RLL", "RRL", "RRLL"};
		for(int i = 1; i <= n; i++){
			for(string g : ok){
				int k = (int)g.size();
				if(i < k) continue;
				int cost = dp[i - k];
				for(int j = 0; j < k; j++){
					if(g[j] != s[i - k + j]) cost += 1;
				}
				dp[i] = min(dp[i], cost);
			}
		}
		ans = min(ans, dp[n]);
		s = s.substr(1) + s.substr(0, 1);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}