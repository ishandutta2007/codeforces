#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
const int mod=1e9+7;
int n,x,dp[maxn],f;

int main(){
    scanf("%d",&n);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        f=(int)sqrt(x);
        for(int j=f;j>=1;j--){
            if(x%j==0){
            if(j*j!=x){
            dp[x/j]+=dp[x/j-1];
            if(dp[x/j]>=mod)
            dp[x/j]-=mod;
            }
            dp[j]+=dp[j-1];
            if(dp[j]>=mod)
            dp[j]-=mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i];
        if(ans>=mod)
        ans-=mod;
    }
    printf("%d\n",ans);
}