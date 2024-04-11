#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k;
long long dp[2010][2010],dp2[2010][2010];
int main(){
    scanf("%d%d",&n,&k);
    dp[1][1]=2;
    dp2[1][2]=2;
    for(int i=2;i<=1001;i++){
        for(int j=1;j<=2*i;j++){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+2*dp2[i-1][j])%mod;
                dp2[i][j]=(dp2[i-1][j]+2*dp[i-1][j-1])%mod;
                if(j>=2)
                    dp2[i][j]+=dp2[i-1][j-2];
                dp[i][j]%=mod,dp2[i][j]%=mod;
        }
    }
    printf("%lld\n",(dp[n][k]+dp2[n][k])%mod);

}