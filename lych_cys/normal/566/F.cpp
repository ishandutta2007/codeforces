#include<bits/stdc++.h>
using namespace std;

int n,a[1000009],dp[1000009];
int main(){
	scanf("%d",&n);
	int i,j;
	for (i=1; i<=n; i++){
		scanf("%d",&j); a[j]++;
	}
	int ans=0;
	for (i=1; i<=1000000; i++){
		dp[i]+=a[i];
		for (j=i+i; j<=1000000; j+=i) dp[j]=max(dp[j],dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}