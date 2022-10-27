#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
long long h[maxn][2];
long long dp[maxn][2];
int main(){
    scanf("%d",&n);
    for(int j=0;j<=1;j++)
    for(int i=1;i<=n;i++){
        scanf("%lld",&h[i][j]);
    }
    dp[1][0]=h[1][0],dp[1][1]=h[1][1];
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+h[i][0]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+h[i][1]);
    }
    printf("%lld\n",max(dp[n][0],dp[n][1]));

}
/*
    Good Luck
        -Lucina
*/