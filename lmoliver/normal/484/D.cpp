#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1001001;
int n;
int a[N];
LL dp[N][3];

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[n+1][1]=0;
	dp[n+1][0]=dp[n+1][2]=INT_MIN;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=2;j++){
			LL &ans=dp[i][j];
			ans=dp[i+1][j];
			if(j!=2)ans=max(ans,dp[i+1][j+1]+a[i]);
			if(j!=0)ans=max(ans,dp[i+1][j-1]-a[i]);
		}
	}
	cout<<dp[1][1]<<endl;
	return 0;
}