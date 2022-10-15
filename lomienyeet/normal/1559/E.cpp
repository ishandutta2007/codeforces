#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
signed main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    int ans[m+1]={};
    for(int i=m;i>0;i--){
        int z=m/i,dp[z+1]={};
        dp[0]=1;
        for(int j=0;j<n;j++){
            for(int k=1;k<=z;k++)(dp[k]+=dp[k-1])%=mod;
            int e[z+1]={};
            for(int k=0;k<=z;k++){
                int wa=(a[j]+i-1)/i,wb=b[j]/i+1;
                if(k>=wa)e[k]=dp[k-wa];
                if(k>=wb)((e[k]-=dp[k-wb])+=mod)%=mod;
            }
            for(int k=0;k<=z;k++)dp[k]=e[k];
        }
        int s=0;
        for(int j=0;j<=z;j++)s+=dp[j];
        ans[i]=s;
        for(int j=i*2;j<=m;j+=i)((ans[i]-=ans[j])+=mod)%=mod;
    }
    cout<<ans[1]<<"\n";
}