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
long long fct[1000005],invfct[1000005],inv[1000005];
long long put2[1000005],invput2[1000005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=invput2[0]=1,put2[1]=2;
    for(long long i=2;i<=1000000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
    invput2[1]=inv[2];
    for(long long i=2;i<=1000000;++i)
        invput2[i]=inv[2]*1LL*invput2[i-1]%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,h,k,m,j,n,s=0,t;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        long long C=m,S=n-m;
        long long ans=0;
        long long sc=0;
        sc=(put2[C]-1+mod)%mod;
        for(long long SS=1;SS<=S;)
        {
            ans=(ans-sc*1LL*invput2[SS+C-1]%mod+mod)%mod;
            ++SS;
            sc=sc*2LL%mod;
            sc=(sc-cmb(SS-2+C,C-1)+mod)%mod;
        }
        ans+=C;
        ans%=mod;
        cout<<(ans*1LL*k)%mod<<'\n';
    }
    return 0;
}