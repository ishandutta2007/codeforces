#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
const int N=1000000;
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
long long fct[N+1],invfct[N+1],inv[N+1];
long long put2[N+1];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=N;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
const int mod=998244353;
int v[1000003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,s,d,m,j=0,tt,p,n,K;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int ok=1;
        for(i=n;i>=n-k+1;--i)
        {
            if(v[i]!=0 && v[i]!=-1)
                ok=0;
            v[i]=0;
        }
        for(i=1;i<=n-k;++i)
        {
            if(v[i]!=-1 && i<=v[i])
                ok=0;
        }
        if(!ok)
        {
            cout<<"0\n";
            continue;
        }
        long long ans=1;
        for(i=1;i<=k;++i)
            ans=ans*1LL*i%mod;
        for(i=1;i<=n;++i)
            if(v[i]==-1)
                ans=ans*1LL*(i+k)%mod;
        for(i=1;i<=n-k;++i)
            if(v[i]==0)
                ans=ans*1LL*(k+1)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}