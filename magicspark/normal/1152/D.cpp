#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,ans;
int dp[2222][2222];
inline void add(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	cin>>n;
	dp[0][0]=1;
	for(int i=0;i<=n+n;i++){
		for(int j=0;j<=n;j++){
			if(j<n&&(j<n+n-i))add(dp[i+1][j+1],dp[i][j]);
			if(j)add(dp[i+1][j-1],dp[i][j]);
			if(i&1)add(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}