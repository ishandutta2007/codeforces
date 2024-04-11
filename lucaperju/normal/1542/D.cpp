#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
struct ura
{
    int fel,val;
}v[505];
long long dp[505][505],n;
long long solve (long long pz)
{
    dp[0][0]=1;
    long long ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i<pz)
            {
                dp[i][j]=dp[i-1][j];
                if(v[i].fel==1)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                    if(j==0)
                        dp[i][j]=(dp[i][j]+dp[i-1][0])%mod;
                }
                else
                {
                    if(v[i].val>v[pz].val)
                        dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                    else if(j>0)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                }
            }
            else if(i==pz)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                if(v[i].fel==1)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
                }
                else
                {
                    if(v[i].val>=v[pz].val)
                        dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                    else if(j>0)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                }
            }
            if(i==n)
                ans=(ans+dp[i][j])%mod;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long i,j;
    int t;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        if(c=='-')
            v[i].fel=1;
        else
        {
            v[i].fel=2;
            cin>>v[i].val;
        }
    }
    long long rz=0;
    for(i=1;i<=n;++i)
    {
        if(v[i].fel==2)
        {
            rz=(rz+solve(i)*1LL*v[i].val%mod)%mod;
        }
    }
    cout<<rz;
    return 0;
}