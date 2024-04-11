#include <bits/stdc++.h>

using namespace std;

/*
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
*/
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,r,s,j,q;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n; /// fing hell, for 10 mins I thought I need to send a subset of heroes
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        long long s=0;
        for(i=1;i<=n;++i)
            s+=v[i];
        cin>>q;
        while(q--)
        {
            long long a,b;
            cin>>a>>b;
            long long k=0,pas=1<<20;
            while(pas)
            {
                if(k+pas<=n && v[k+pas]<=a)
                    k+=pas;
                pas>>=1;
            }
            if(k==0)
                ++k;
            long long ans=max(0LL,a-v[k])+max(0LL,(b-(s-v[k])));
            ++k;
            if(k>n)
            {
                cout<<ans<<'\n';
                continue;
            }
            ans=min(ans,max(0LL,a-v[k])+max(0LL,(b-(s-v[k]))));
            cout<<ans<<'\n';
        }
    }
    return 0;
}