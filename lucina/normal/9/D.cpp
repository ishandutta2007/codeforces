#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,h;
ll ans,dp[50][50];
/*
dp[i][j]=number of BST of depth j with i node

*/
int main(){
    scanf("%d%d",&n,&h);
    //catalan[0]=1;
    //catalan[1]=1;
    ans=1;
    /*for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            catalan[i]+=(catalan[j]*catalan[i-j-1]);
        }
    }*/
    dp[1][0]=1ll,dp[0][0]=1ll;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=i;k++){
                    ll keep=0;
                    for(int l=0;l<=j-2;l++)
                        keep+=(dp[i-k][l]);
                dp[i][j]+=(dp[k-1][j-1]*(keep));
                keep=0;
                for(int l=0;l<=j-2;l++)
                    keep+=(dp[k-1][l]);
                dp[i][j]+=(dp[i-k][j-1]*keep);
                dp[i][j]+=(dp[i-k][j-1]*dp[k-1][j-1]);
            }
        }
    }
    ans=0;
    for(int i=h-1;i<=n;i++)
        ans+=dp[n][i];
    printf("%lld\n",ans);


}