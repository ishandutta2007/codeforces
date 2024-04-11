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
int a[200005],b[200005],lin[200005],col[200005],fl,fc;
const int mod=998244353 ;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,x,i,y,k,m,j=0,n,tt,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>q;
        for(i=1;i<=q;++i)
        {
            cin>>a[i]>>b[i];
            lin[a[i]]=0;
            col[b[i]]=0;
        }
        fl=n,fc=m;
        long long ans=1;
        for(i=q;i>=1;--i)
        {
            if(fl==0 || fc==0)
                break;
            if(!lin[a[i]] || !col[b[i]])
                ans=(ans*1LL*k)%mod;
            if(lin[a[i]]==0)
                --fl;
            if(col[b[i]]==0)
                --fc;
            lin[a[i]]=col[b[i]]=1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}