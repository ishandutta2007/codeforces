#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int r, n;
	cin >> r >> n;
	n++;
	vector<int> t(n, 0), x(n, 0), y(n, 0);
	vector<int> dp(n, -1e8);
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		cin >> t[i] >> x[i] >> y[i];
		x[i]--; y[i]--;
	}
	vector<int> pdp(n, -1e8);
	pdp[0] = 0;
	const int F = 1100;
	for(int i = 1; i < n; i++){
		for(int g = i-1; g >= 0 && g >= i-F; g--){
			if(abs(x[i] - x[g]) + abs(y[i] - y[g]) <= t[i] - t[g]){
				dp[i] = max(dp[i], dp[g] + 1);
			}
		}
		if(i >= F) dp[i] = max(dp[i], pdp[i-F] + 1);
		pdp[i] = max(dp[i], pdp[i-1]);
	}
	cout << pdp[n-1] << '\n';
}