#include <bits/stdc++.h>
using namespace std;
long long v[200003];
long long sp[200003];
long long dp[200003],cat[200003];
map<long long,long long>mp;
const long long mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        mp[0]=1;
        dp[0]=1;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            sp[i]=v[i]+sp[i-1];
            dp[i]=(dp[i-1]*2LL-mp[sp[i-1]]+mod)%mod;
            cat[i]=(dp[i-1]-mp[sp[i-1]]+mod)%mod;
            if(i!=1)
                mp[sp[i-1]]=(mp[sp[i-1]]+cat[i]+mod)%mod;
        }
        cout<<dp[n]<<'\n';
        for(i=1;i<=n;++i)
        {
         //   cout<<dp[i]<<' ';
            mp[sp[i]]=0;
        }
    }
    return 0;
}