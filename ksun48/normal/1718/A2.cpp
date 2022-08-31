#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> dp(n+1, n);
	map<int,int> ploc;
	ploc[0] = 0;
	dp[0] = 0;
	int cur = 0;
	for(int i = 0; i < n; i++){
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		if(a[i] == 0) dp[i+1] = min(dp[i+1], dp[i]);
		cur ^= a[i];
		if(ploc.count(cur)){
			int x = ploc[cur];
			dp[i+1] = min(dp[i+1], dp[x] + (i+1-x-1));
		}
		ploc[cur] = i+1;
	}
	cout << dp[n] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}