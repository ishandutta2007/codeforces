#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[5005][5005];//1 to i form j teams' ans
int n,k,a[5005],to[5005];
int main(){
	cin>>n>>k;memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n&&a[j]-a[i]<=5;j++){
			to[i]=j;
		}to[i]++;
	}
	dp[1][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(!~dp[i][j])continue;
		//	cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			dp[to[i]][j+1]=max(dp[i][j]+to[i]-i,dp[to[i]][j+1]);
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	}
	cout<<*max_element(&dp[n+1][0],&dp[n+1][k+1])<<endl;
	return 0;
}