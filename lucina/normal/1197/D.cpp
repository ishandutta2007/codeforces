#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
const long long inf=1e17;
int n,k,m;
long long a[maxn],dp[maxn][11],ans;
void upd(long long &x,long long y){
    if(x<y)x=y;return;
}
 
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        dp[i][j]=-inf;
   // dp[0][0]=0;
    /**
    dp[i][j] = the maximum cost of sub-array ending with i
    and the length modulo m is j
    */
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(j==0)upd(dp[i][j],max(a[i]-k,dp[i-1][m-1]+a[i]-k));
            else upd(dp[i][j],dp[i-1][j-1]+a[i]);
            upd(ans,dp[i][j]);
        }
    }
    printf("%lld\n",ans);
}