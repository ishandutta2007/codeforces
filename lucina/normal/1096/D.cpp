#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
const long long big=1e18;
long long dp[maxn][5];
int n,a[maxn];
char s[maxn];

int main(){
    char fuck[5];
    fuck[0]='h',fuck[1]='a',fuck[2]='r',fuck[3]='d';
    for(int i=0;i<=int(1e5+10);i++)
        for(int j=0;j<=4;j++)
        dp[i][j]=big;
    scanf("%d %s",&n,s);
    dp[0][0]=0;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(s[i]==fuck[j]){
            dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
            }
            else
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        }
    }
    long long ans=big;
    for(int i=0;i<4;i++)
        ans=min(ans,dp[n][i]);
    printf("%lld\n",ans);
    /*
    remove dp[i+1][j]=dp[i][j]+a[i];
    keep dp[i+1][j+1]=dp[i][j]
    */
}