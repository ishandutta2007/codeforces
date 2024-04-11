#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<vector<int> > cost(n+1, vector<int>(n+1));
	for(int i = 0; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			set<int> r;
			for(int k = i; k < j; k++){
				r.insert(a[k]);
			}
			int mex = 0;
			while(r.count(mex)) mex++;
			cost[i][j] = mex + 1;
		}
		cost[i][i] = 0;
	}
	for(int k = 0; k <= n; k++){
		for(int i = 0; i <= k; i++){
			for(int j = k; j <= n; j++){
				cost[i][j] = max(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j <= n; j++){
			ans += cost[i][j];
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