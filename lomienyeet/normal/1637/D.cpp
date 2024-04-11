#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int a[n+1],b[n+1],ps[n+1]={},ans=0,s=0,qwq=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i]*a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        ans+=b[i]*b[i];
        s+=b[i];
        ps[i]=ps[i-1]+a[i]+b[i];
    }
    ans*=n-1;
    int dp[n+1][s+1];
    memset(dp,1,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=qwq;j++){
            dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*j+b[i]*(ps[i-1]-j));
            dp[i][j+b[i]]=min(dp[i][j+b[i]],dp[i-1][j]+b[i]*j+a[i]*(ps[i-1]-j));
        }
        qwq+=a[i]+b[i];
    }
    int pp=1e18;
    for(int i=0;i<=qwq;i++)pp=min(pp,dp[n][i]);
    cout<<pp*2+ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}