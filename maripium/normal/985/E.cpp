#include <bits/stdc++.h>

using namespace std;
int dp[500005];
int jump[500005];
int a[500005];
signed main()
{
	int n,k,d;
	cin>>n>>k>>d;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	memset(dp, 0, sizeof dp);
	int cur = 1; dp[0] = 1;
	
	if(a[k] - a[1] <= d) dp[k] = 1;
	for(int i = k + 1;i <= n; i++) {
		while(a[i] - a[cur] > d && cur <= n) {
			cur++;
		}
		while(dp[cur - 1] == 0 && cur <= n) {
			cur++;
		}
		if(cur <= i - k + 1){
		 	dp[i] = 1;
		}
	}
	if(dp[n]){
		cout<<"YES"; 
		return 0;
	}
	cout<<"NO";
}