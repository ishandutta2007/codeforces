#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll a,b,dp[202020][2];
char s[202020];
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %lld %lld",&n,&a,&b);
    	scanf("%s",s+1);

    	dp[0][0] = b;
    	dp[0][1] = 1e18;

    	for(int i=1;i<=n;i++){
    		if(s[i] == '1' || s[i+1] == '1') dp[i][0] = 1e18, dp[i][1] = min(dp[i-1][0] + a, dp[i-1][1]) + a + 2*b;
    		else dp[i][0] = min(dp[i-1][0], dp[i-1][1] + a) + a + b, dp[i][1] = min(dp[i-1][0] + a, dp[i-1][1]) + a + 2*b;
    	}

    	printf("%lld\n",dp[n][0]);
    	for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = 0;
    }
}