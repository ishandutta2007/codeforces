#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int t[n+1];
	for(int i = 0; i < n; i++) scanf("%d", &t[i+1]);
	int dp[n+1];
	int a = 1;
	int b = 1;
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i-1]+20;
		while(t[a] + 89 < t[i]) a++;
		while(t[b] + 1439 < t[i]) b++;
		dp[i] = min(dp[i], dp[a-1]+50);
		dp[i] = min(dp[i], dp[b-1]+120);
		printf("%d\n", dp[i]-dp[i-1]);
	}
}