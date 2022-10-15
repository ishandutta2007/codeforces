#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int h,w,x;
    cin>>h>>w>>x;
    int aa[h+1][w],bb[h][w+1];
    for(int i=1;i<=h;i++){
        for(int j=1;j<w;j++)cin>>aa[i][j];
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<=w;j++)cin>>bb[i][j];
    }
    if(x&1){
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++)cout<<"-1 ";
            cout<<"\n";
        }
        return;
    }
    x/=2;
    int dp[x+1][h+1][w+1];
    for(int i=0;i<=x;i++){
        for(int j=1;j<=h;j++){
            for(int k=1;k<=w;k++)dp[i][j][k]=0;
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=h;j++){
            for(int k=1;k<=w;k++){
                dp[i][j][k]=1e9;
                if(j>1)dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][k]+bb[j-1][k]);
                if(k>1)dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-1]+aa[j][k-1]);
                if(j<h)dp[i][j][k]=min(dp[i][j][k],dp[i-1][j+1][k]+bb[j][k]);
                if(k<w)dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k+1]+aa[j][k]);
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)cout<<dp[x][i][j]*2<<" ";
        cout<<"\n";
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--)eat();
}