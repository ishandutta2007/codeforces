#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	const int F = 20000;
	vector<int> dp(F, 0);
	dp[0] = 1;
	for(int i = 0; i < F; i++){
		if(i >= 11) dp[i] |= dp[i-11];
		if(i >= 111) dp[i] |= dp[i-111];
		if(i >= 1111) dp[i] |= dp[i-1111];
		if(i >= 11111) dp[i] |= dp[i-11111];
	}
	int T;
	cin >> T;
	while(T--) {
		int x;
		cin >> x;
		if(x > F){
			x %= (11 * 111);
			x += 2 * 11 * 111;
		}
		cout << (dp[x] ? "YES" : "NO") << '\n';
	}
}