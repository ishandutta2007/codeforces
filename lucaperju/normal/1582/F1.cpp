#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
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
/*/
int dp[100005][515];
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=0;i<512;++i)
        dp[0][i]=1000;
    dp[0][0]=0;
    for(i=1;i<=n;++i)
    {
        for(j=0;j<512;++j)
            dp[i][j]=dp[i-1][j];
        for(j=0;j<512;++j)
        {
            if(dp[i-1][j]!=1000 && dp[i-1][j]<v[i])
                dp[i][j^v[i]]=min(dp[i][j^v[i]],v[i]);
        }
    }
    vector<int>rz;
    for(j=0;j<512;++j)
        if(dp[n][j]!=1000)
            rz.push_back(j);
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
        cout<<rz[i]<<' ';
}