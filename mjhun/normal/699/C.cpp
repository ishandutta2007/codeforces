#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n;
int a[128];
int dp[128][3];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	for(int i=1;i<=n;++i){
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i-1][2]+1;
		if(a[i-1]&1){
			dp[i][1]=min(dp[i][1],dp[i-1][0]);
			dp[i][2]=min(dp[i][2],dp[i-1][0]);
		}
		if(a[i-1]&2){
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
			dp[i][2]=min(dp[i][2],dp[i-1][1]);
		}
	}
	printf("%d\n",dp[n][2]);
	return 0;
}