#include <bits/stdc++.h>

using namespace std;


const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}

int v[200005];
int cv[200005];
long long put2p[200005];
map<int,int>mp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n;
    put2[0]=1;
    for(i=1;i<=200001;++i)
        put2[i]=put2[i-1]*2LL%mod;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==0)
        {
            cout<<1<<'\n';
            continue;
        }
        if(n%2==1)
        {
            long long rz=1;
            for(i=1;i<=k;++i)
            {
                rz=rz*1LL*(put2[n-1]+1)%mod;
            }
            cout<<rz<<'\n';
            continue;
        }
        long long rz=0;
        put2p[1]=put2[n];
        for(i=2;i<=k;++i)
            put2p[i]=put2p[i-1]*1LL*put2[n]%mod;
        put2p[0]=1;
        long long coefc=1;
        for(i=k;i>=1;--i)
        {
            rz=(rz+put2p[i-1]*1LL*coefc%mod)%mod;
            coefc=coefc*1LL*(put2[n-1]-1)%mod;
        }
        rz=(rz+coefc)%mod;
        cout<<rz<<'\n';
    }
    return 0;
}