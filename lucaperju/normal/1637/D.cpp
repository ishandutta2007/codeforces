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
int a[103],b[103],sp[103];
long long dp[103][100003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,h,k,m,j=0,n,s=0,tt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=n;++i)
        {
            cin>>b[i];
            sp[i]=sp[i-1]+a[i]+b[i];
        }
        for(i=0;i<=n;++i)
            for(j=0;j<=n*100;++j)
                dp[i][j]=2000000000;
        dp[0][0]=0;
        for(i=1;i<=n;++i)
        {
            for(j=0;j<=n*100;++j)
            {
                if(dp[i-1][j]==2000000000)
                    continue;
                dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*1LL*j+b[i]*1LL*(sp[i-1]-j));
                swap(a[i],b[i]);
                dp[i][j+a[i]]=min(dp[i][j+a[i]],dp[i-1][j]+a[i]*1LL*j+b[i]*1LL*(sp[i-1]-j));
            }
        }
        long long mn=2000000000;
        for(j=0;j<=n*100;++j)
            mn=min(mn,dp[n][j]);
        long long s=0;
        for(i=1;i<=n;++i)
        {
            s=s+a[i]*1LL*a[i]*1LL*(n-1);
            s=s+b[i]*1LL*b[i]*1LL*(n-1);
        }
        cout<<s+mn+mn<<'\n';
    }
    return 0;
}