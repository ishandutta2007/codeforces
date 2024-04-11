#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,a[N],dp[N],t;
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		sort(a+1,a+n+1);
		dp[0] = 0;
		for(int i = 1;i <= n;++i)
			if(a[i] <= i) dp[i] = max(dp[i-1],dp[i-a[i]]+1);
			else dp[i] = dp[i-1];
		cout << dp[n] << endl;
	}
	return 0;
}