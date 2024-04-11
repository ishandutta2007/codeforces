#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,cnt[1000005],dp[1000005][5][3];
int main(){
	scanf("%d%d",&n,&m);
	while(n--){int t;scanf("%d",&t);cnt[t]++;}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=4;j++)
			for(int k=0;k<=2;k++){
				if(dp[i-1][j][k]>=0){
					for(int l=0;l<=min(j,min(k,cnt[i]));l++){
						int y=cnt[i]-l;
						int z=y%3;
						dp[i][z][min(j-l,2)]=max(dp[i][z][min(j-l,2)],dp[i-1][j][k]+l+(y-z)/3);
						if(y>=z+3)dp[i][min(4,z+3)][min(j-l,2)]=max(dp[i][min(4,z+3)][min(j-l,2)],dp[i-1][j][k]+l+(y-z)/3-1);
					}
				}
			}
	int ans=0;for(int i=0;i<=4;i++)for(int j=0;j<=2;j++)ans=max(ans,dp[m][i][j]);
	printf("%d\n",ans);
	return 0;
}