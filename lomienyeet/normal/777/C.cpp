#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>arr[i][j];
    }
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=i;
    for(int i=0;i<m;i++){
        int ptr=0;
        for(int j=1;j<n;j++){
            if(arr[j][i]>=arr[j-1][i])dp[ptr]=max(dp[ptr],j);
            else ptr=j;
        }
    }
    for(int i=1;i<n;i++)dp[i]=max(dp[i],dp[i-1]);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(dp[l]>=r)cout<<"Yes\n";
        else cout<<"No\n";
    }
}