#include <bits/stdc++.h>

using namespace std;


const long long mod = 998244353;

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
int lsb (int x)
{
    return x&-x;
}
long long aib[200005];
long long values[200005];
void upd1 (int pz, long long val)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        aib[i]=(aib[i]+val)%mod;
}
void upd (int pz, long long val)
{
    long long dif=((values[pz]*1LL*val%mod)-values[pz]+mod)%mod;
    values[pz]=values[pz]*1LL*val%mod;
    for(int i=pz;i<=200000;i+=lsb(i))
        aib[i]=(aib[i]+dif+mod)%mod;
}
long long qry (int pz)
{
    long long rz=0;
    for(int i=pz;i>0;i-=lsb(i))
        rz=(rz+aib[i])%mod;
    return rz;
}
int v1[200003],v2[200003],fv[200003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,x,i,y,k,m,j=0,n,tt,s=0,c;
    //cin>>t;
    init();
    t=1;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            cin>>v1[i];
            ++fv[v1[i]];
        }
        for(i=1;i<=m;++i)
            cin>>v2[i];
        long long p=fct[n-1];
        for(i=1;i<=200000;++i)
            p=p*1LL*invfct[fv[i]]%mod;
        for(i=1;i<=200000;++i)
            if(fv[i])
            {
                values[i]=p*1LL*fv[i]%mod;
                upd1(i,p*1LL*fv[i]%mod);
            }
        long long s=0;
        long long global=1;
        for(i=1;i<=n;++i)
        {
            s=(s+global*1LL*qry(v2[i]-1)%mod)%mod;
            int vlc=v2[i];
            if(fv[vlc]==0)
                break;
            --fv[vlc];
            global=global*1LL*inv[n-i]%mod;
            global=global*1LL*(fv[vlc]+1)%mod;
            upd(vlc,inv[fv[vlc]+1]*1LL*fv[vlc]%mod);
        }
        if(i==n+1 && i<=m)
        {
            s=(s+1)%mod;
        }
        cout<<s;
    }
    return 0;
}