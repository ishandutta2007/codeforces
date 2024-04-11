#include <bits/stdc++.h>
using namespace std;
const int mxN=1048576;
signed main(){
    string s;
    cin>>s;
    int n=s.length(),dp[mxN]={};
    for(int i=0;i<n;i++){
        int msk=0;
        for(int j=i;j<n;j++){
            if(msk&(1<<(s[j]-'a')))break;
            msk^=(1<<(s[j]-'a'));
            dp[msk]=j-i+1;
        }
    }
    for(int i=0;i<mxN;i++){
        for(int j=0;j<20;j++){
            if(!(i&(1<<j)))continue;
            dp[i]=max(dp[i],dp[i^(1<<j)]);
        }
    }
    int maxi=0;
    for(int i=0;i<mxN;i++)maxi=max(maxi,dp[i]+dp[mxN-i-1]);
    cout<<maxi<<"\n";
}