#include<bits/stdc++.h>
#define N 300005
using namespace std;
int n,a[N],dp[N];
int main(){
	scanf("%d",&n);
	int j,k,i;
	for (i=1,j=k=1; i<=n; i++){
		scanf("%d",&a[i]);
		dp[i]=dp[i-1]+20;
		for (; j<i && a[j]+90<=a[i]; j++);
		if (j<i) dp[i]=min(dp[i],dp[j-1]+50);
		for (; k<i && a[k]+1440<=a[i]; k++);
			if (k<i)dp[i]=min(dp[i],dp[k-1]+120);
				printf("%d\n",dp[i]-dp[i-1]);
	}
	return 0;
}