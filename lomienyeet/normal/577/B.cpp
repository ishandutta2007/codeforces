#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    if(n>m){
        cout<<"YES\n";
        return 0;
    }
    bool dp[2][m+1];
    memset(dp,0,sizeof dp);
    dp[0][0]=dp[1][0]=1;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        x=(x-1)%m+1;
        for(int j=m;j>0;j--)dp[i&1][j]=dp[!(i&1)][j]|dp[!(i&1)][(j-x+m)%m];
    }
    cout<<(dp[n&1][m]?"YES\n":"NO\n");
}