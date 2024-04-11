#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
*/
int a[100005],b[100005];
long long sa[100005],sb[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,j,k,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=n;++i)
            cin>>b[i];
        sa[n+1]=0;
        for(i=n;i>=1;--i)
        {
            sa[i]=sa[i+1]+a[i];
        }
        for(i=1;i<=n;++i)
            sb[i]=sb[i-1]+b[i];
        long long mn=sa[1]+sb[n];
        for(i=1;i<=n;++i)
            mn=min(mn,max(sa[i+1],sb[i-1]));
        cout<<mn<<'\n';
    }
    return 0;
}