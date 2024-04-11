#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int v[100005];
int dp[100005][7];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,tt,p,z;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>z;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=0;i<=n;++i)
            for(j=0;j<=z;++j)
                dp[i][j]=-1000000000;
        dp[0][0]=0;
        for(i=0;i<=k;++i)
        {
            for(j=0;j<=min(i,z);++j)
            {
                int pz=1+i-j-j;
                if(pz>1)
                {
                    dp[i+2][j+1]=max(dp[i+2][j+1],dp[i][j]+v[pz]+v[pz-1]);
                }
                if(pz<n)
                {
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+v[pz+1]);
                }
                if(i==k-1)
                {
                    if(pz>1)
                    {
                        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+v[pz-1]);
                    }
                }
            }
        }
        int mx=-1000000000;
        for(i=0;i<=z;++i)
            mx=max(mx,dp[k][i]);
        cout<<mx+v[1]<<'\n';
    }
    return 0;
}