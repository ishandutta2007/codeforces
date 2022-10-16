#include <bits/stdc++.h>
using namespace std;


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
long long fct[600005],invfct[600005],inv[600005];
long long put2[600005];
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

int main()
{
    int i,j,m,n,k=0,q,n1,n2;
    init();
    cin>>n>>k;
    if(k>=n)
    {
        cout<<put2[n];
        return 0;
    }
    long long s=put2[n];
    for(i=1;i<=n;++i)
        s=(s-cmb(i-1,k-1)*1LL*(put2[n-i]-1)%mod+mod)%mod;
    cout<<s;
    return 0;
}