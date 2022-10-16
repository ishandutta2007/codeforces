#include <bits/stdc++.h>

using namespace std;
int v[2003];
int dp[2003][2003];
int main()
{
    int t,n,i,j,k,cnt=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        cin>>v[i];
        for(i=1;i<=n;++i)
            for(j=1;j<=i;++j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+(v[i]==j));
        for(i=n;i>=1;--i)
            if(dp[n][i]>=k)
                break;
        if(i==0)
            cout<<"-1\n";
        else
            cout<<n-i<<'\n';
    }
    return 0;
}