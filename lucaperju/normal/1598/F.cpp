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
char v[400005];
int cat[21][400005];
int s[21],mn[21];
int dp[1050000];
int sumc[1050000];
const int off=400000;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);/// oops this was from the last contest
    long long n,m,q,t,i,j,k;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v;
        int nc=strlen(v);
        int sc=0;
        int mnc=0;
        for(j=0;j<nc;++j)
        {
            if(v[j]==')')
                --sc;
            else
                ++sc;
            if(sc<=mnc)
                ++cat[i][-sc];
            mnc=min(mnc,sc);
        }
        mn[i]=mnc;
        s[i]=sc;
    }
    int ans=0;
    for(i=0;i<(1<<n);++i)
        dp[i]=-9999999;
    dp[0]=0;
    int pz,bit;
    for(int mask=0;mask<(1<<n);++mask)
    {
        ans=max(ans,dp[mask]);
        if(dp[mask]<0)
            continue;
        for(pz=1;pz<=n;++pz)
        {
            bit=pz;
            if(mask&(1<<(bit-1)))
                continue;
            bit=(1<<(bit-1));
            ans=max(ans,cat[pz][sumc[mask]]+dp[mask]);
            if(sumc[mask]+mn[pz]>=0)
                dp[mask|bit]=max(dp[mask|bit],cat[pz][sumc[mask]]+dp[mask]);
            sumc[mask|bit]=sumc[mask]+s[pz];
        }
    }
    cout<<ans;
    return 0;
}