#include <cstdio>
#include <iostream>
#define INF 1000000
using namespace std;

int dp[4096];


int main(){
    int n,a,b,c,i;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    dp[0]=0;
    for(i=1;i<=n;++i){
        dp[i]=-INF;
        if(i>=a){
            dp[i]=max(dp[i],1+dp[i-a]);
        }
        if(i>=b){
            dp[i]=max(dp[i],1+dp[i-b]);
        }
        if(i>=c){
            dp[i]=max(dp[i],1+dp[i-c]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}