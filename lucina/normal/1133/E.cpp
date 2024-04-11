#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;;
int n,k,u,ans,dp[maxn][maxn],a[maxn];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int pt=1;
    for(int i=1;i<=n;i++){
        while(a[i]-a[pt]>5)
            pt++;
        for(int j=1;j<=k;j++){
            dp[i][j]=max(dp[i-1][j],dp[pt-1][j-1]+(i-pt+1));
        }
    }
    for(int i=1;i<=k;i++){
        ans=max(ans,dp[n][i]);
    }
    printf("%d\n",ans);
}