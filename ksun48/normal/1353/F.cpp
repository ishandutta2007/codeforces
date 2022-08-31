#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<ll> > a(n, vector<ll>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			a[i][j] -= (i+j);
		}
	}
	vector<vector<ll> > dp(n, vector<ll>(m));
	const ll INF = ll(2e18);
	ll ans = INF;
	for(auto& x : a){
		for(ll v : x){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(i == 0 && j == 0){
						dp[i][j] = 0;
					} else if(i == 0){
						dp[i][j] = dp[i][j-1];
					} else if(j == 0){
						dp[i][j] = dp[i-1][j];
					} else {
						dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
					}
					if(a[i][j] < v){
						dp[i][j] = INF;
					} else {
						dp[i][j] += (a[i][j] - v);
					}
					dp[i][j] = min(dp[i][j], INF);
				}
			}
			ans = min(ans, dp.back().back());
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}