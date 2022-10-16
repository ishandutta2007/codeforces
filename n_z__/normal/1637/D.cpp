#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[101][10105];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1],b[n+1];
		int sum=0;
		for(int i=1;i<=n;i++){ cin>>a[i]; sum+=a[i];}
		for(int i=1;i<=n;i++){ cin>>b[i]; sum+=b[i];}
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=10000;j++){
				if(dp[i-1][j]){
					dp[i][j+a[i]]=1;
					dp[i][j+b[i]]=1;
				}
			}
		}
		int sump=0;
		for(int i=1;i<=n;i++){
			sump+=(a[i]*a[i]+b[i]*b[i]);
		}
		sump*=(n-2);
		int minv=1e18;
		for(int i=0;i<=10000;i++){
			if(dp[n][i]){
				minv=min(minv,i*i+(sum-i)*(sum-i));
			}
		}
		cout<<sump+minv<<endl;
	}
	return 0;
}