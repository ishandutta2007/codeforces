#include<bits/stdc++.h>
using namespace std;
int n,dp[510][510];
char s[510];

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=1e9;
            for(int k=i;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-(s[i]==s[j]));
            }
        }
    }
    printf("%d\n",dp[1][n]);
}