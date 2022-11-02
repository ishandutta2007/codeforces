#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=5005,mod=998244353;
int T,n,a[N],dp[N][N],C[N][N],lim[N];
int main() {
    C[0][0]=1;
    rep(i,N-1){
        C[i][0]=1;
        rep(j,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        int len=n/2;
        for(int i=0;i<=len;++i)
            for(int j=0;j<=len;++j)
                dp[i][j]=0;
        for(int i=0;i<=len;++i)
            lim[i]=max(0,i-1+(i==len));
        dp[0][0]=1;
        for(int u=n,v;u;u=v){
            for(v=u;v&&a[v]==a[u];--v);
            int cnt=u-v,now=n-u;
            for(int i=0;i<=now&&i<=len;++i){
                int j=now-i;
                //printf("%d %d %d\n",i,j,dp[i][j]);
                //root leaf
                if(lim[i]>=j){
                    dp[i][j+cnt]=(dp[i][j+cnt]+(ll)dp[i][j]*C[lim[i]-j][cnt])%mod;
                    //printf("l:%d %d %d\n",lim[i]-j,cnt,C[lim[i]-j][cnt]);
                }
                if(lim[i]>=j&&i+1<=len)
                    dp[i+1][j+cnt-1]=(dp[i+1][j+cnt-1]+(ll)dp[i][j]*C[lim[i]-j][cnt-1])%mod;
            }
        }
        printf("%d\n",dp[len][len]);
    }
    return 0;
}