#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353; // wtf
signed main(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=1;i<=n;i++)dp[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=i*2;j<=n;j+=i)dp[j]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        (dp[i]+=ans)%=mod;
        (ans+=dp[i])%=mod;
    }
    cout<<dp[n]<<"\n";
}