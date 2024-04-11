#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops")
using namespace std;
#define int long long
int dp[450][100005];
void eat(){
    int n;
    cin>>n;
    int s=0,mx=0;
    while(s<=n){
        mx++;
        s+=mx;
    }
    mx--;
    int arr[n+1],ps[n+1]={};
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+arr[i];
    for(int i=0;i<=mx+1;i++){
        for(int j=0;j<=n+1;j++)dp[i][j]=0;
    }
    for(int i=0;i<=mx;i++){
        for(int j=n+1;j>0;j--){
            if(!i)dp[i][j]=9e18;
            else if(j==n+1)dp[i][j]=0;
            else{
                dp[i][j]=dp[i][j+1];
                if(i+j-1<=n){
                    int wa=ps[i+j-1]-ps[j-1];
                    if(dp[i-1][i+j]>wa)dp[i][j]=max(dp[i][j],wa);
                }
            }
        }
    }
    int ans=0;
    while(dp[ans][1]>0)ans++;
    cout<<ans-1<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)eat();
}