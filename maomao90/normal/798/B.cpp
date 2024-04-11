#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string s[n+1];
    for(int i=1;i<=n;i++)
    cin>>s[i];
    int k=s[1].size();
    
    int dp[n+1][s[1].size()];
    for(int i=0;i<k;i++)
    dp[1][i]=i;
    for(int i=2;i<=n;i++)
    for(int j=0;j<k;j++)
    dp[i][j]=1e5;
    
    for(int i=1;i<=n;i++)
    s[i]=s[i]+s[i];
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int prev=0;prev<k;prev++)
            {
                if(s[i].substr(j,k)==s[i-1].substr(prev,k))
                dp[i][j]=min(dp[i][j],dp[i-1][prev]+j);
            }
        }
    }
 
    int ma=1e5;
    for(int i=0;i<k;i++)
    {ma=min(dp[n][i],ma);
 
    }
    if(ma==1e5)
    cout<<-1;
    else
    cout<<ma;
}