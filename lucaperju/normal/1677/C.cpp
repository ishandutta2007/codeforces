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
struct ura
{
    int a,b;
}v[100005];
int newcol[100005];
int viz[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,s,d,m,j=0,tt,p,n,K;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i].a;
        for(i=1;i<=n;++i)
            cin>>v[i].b;
        for(i=1;i<=n;++i)
            newcol[v[i].a]=i;
        for(i=1;i<=n;++i)
        {
            viz[i]=0;
            v[i].a=newcol[v[i].a];
            v[i].b=newcol[v[i].b];
        }
        s=0;
        for(i=1;i<=n;++i)
        {
            if(viz[i])
                continue;
            int pz=i,cnt=1;
            viz[i]=1;
            while(v[pz].b!=i)
            {
                pz=v[pz].b;
                viz[pz]=1;
                ++cnt;
            }
            s+=cnt/2;
        }
        long long ans=0;
        for(i=1;i<=s;++i)
            ans-=(i+i);
        for(i=n;i>=n-s+1;--i)
            ans+=(i+i);
        cout<<ans<<'\n';
    }
    return 0;
}