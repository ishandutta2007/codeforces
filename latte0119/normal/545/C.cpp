#include<bits/stdc++.h>
using namespace std;
#define int long long
int N;
int x[100002],h[100002];

int dp[100001][2];
signed main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d%d",&x[i+1],&h[i+1]);
    x[0]=INT_MIN;
    x[N+1]=INT_MAX;
    h[0]=0;
    h[N+1]=0;
    for(int i=1;i<=N;i++){
        int m=max(dp[i-1][0],dp[i-1][1]);
        if(x[i]-h[i]>x[i-1]+h[i-1]){
            dp[i][0]=m+1;
        }
        else if(x[i]-h[i]>x[i-1]){
            dp[i][0]=dp[i-1][0]+1;
        }
        else dp[i][0]=m;

        if(x[i]+h[i]<x[i+1]){
            dp[i][1]=m+1;
        }
        else dp[i][1]=m;
    }
    printf("%d\n",max(dp[N][0],dp[N][1]));
    return 0;
}