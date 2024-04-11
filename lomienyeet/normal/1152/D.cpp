#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2022,mod=1e9+7;
pair<int,int> dp[mxN][mxN]; // {can, subtree}
signed main(){
	int n;
	cin>>n;
	n<<=1;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]={0,0};
	dp[0][0]={1,0};
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j){
				dp[i][j].ff|=dp[i-1][j-1].ff;
				(dp[i][j].ss+=dp[i-1][j-1].ss)%=mod;
			}
			if(j+1<i){
				dp[i][j].ff|=dp[i-1][j+1].ff;
				(dp[i][j].ss+=dp[i-1][j+1].ss)%=mod;
			}
			dp[i][j].ss+=dp[i][j].ff;
			dp[i][j].ff^=1;
		}
	}
	cout<<dp[n][0].ss%mod<<"\n";
}