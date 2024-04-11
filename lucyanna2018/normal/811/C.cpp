#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int val[5555],lef[5555],rig[5555],vis[5555],dp[5555];
int main(){
	scanf("%d",&n);
	for(int i=0; i<=5000; i++){
		lef[i] = n+1;
		rig[i] = -1;
	}
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		val[i] = x;
		if(lef[x] > i)lef[x] = i;
		if(rig[x] < i)rig[x] = i;
	}
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		int sum = 0, lvalid = n;
		dp[i] = dp[i-1];
		for(int j=i; j>=1; j--){
			lvalid = min(lvalid, j);
			int x = val[j];
			if(rig[x] > i)break;
			lvalid = min(lvalid, lef[x]);

			if(vis[x] != i){
				vis[x] = i;
				sum ^= x;
			}

			if(lvalid == j){
				dp[i] = max(dp[i], dp[j-1] + sum);
			}
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}