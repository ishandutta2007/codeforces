#include<bits/stdc++.h>
const int N=210;
int n,d,mod,ans,C[N][N],dp[N][N],sum[N];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&d,&mod);
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=((long long)C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			dp[1][0]=1;
		}else{
			dp[i][1]=sum[i-1];
			for(int j=2;j<i&&j<=d;j++)
				for(int k=1;k<i;k++){
					dp[i][j]=(dp[i][j]+(long long)dp[k][j-1]*sum[i-k]%mod*C[i-2][k-1])%mod;
				}
		}
		for(int j=0;j<d;j++)sum[i]=((long long)sum[i]+dp[i][j])%mod;
	}
	// for(int i=1;i<=n;i++)
	// 	for(int j=0;j<=d;j++)
	// 		printf("%d%c",dp[i][j]," \n"[j==d]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=d;j++)
			for(int k=0;j+k<=d;k++){
				ans=(ans+(long long)dp[i][j]*dp[n-i+1][k])%mod;
			}
	for(int i=1;i<=n;i++)
		for(int j=0;j<d;j++)
			for(int k=0;k<d;k++){
				ans=(ans-(long long)dp[i][j]*dp[n-i][k])%mod;
			}
	ans=(long long)ans*n%mod*(n-1)%mod*2%mod;
	printf("%d\n",ans<0?ans+mod:ans);
}