#include <bits/stdc++.h>
using namespace std;
char vi[100005];
long long v[100005];
long long sp[100005];
const long long mod=1000000007;
long long put10[100005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k=0,n,q,m,ans=0;
    cin>>(vi+1);
    n=strlen(vi+1);
    for(i=1;i<=n;++i)
        v[i]=vi[i]-'0';
    put10[0]=1;
    for(i=1;i<=n;++i)
        put10[i]=(put10[i-1]*10LL)%mod;
    for(i=1;i<=n;++i)
        sp[i]=sp[i-1]+v[i];
    for(int putc=0;putc<n-1;++putc)
    {
        long long rzc=0;
        rzc=(rzc+(putc+1)*1LL*(sp[n-putc-1])%mod)%mod;
        rzc=(rzc*1LL*put10[putc])%mod;
        ans=(ans+rzc)%mod;
    }
    for(i=1;i<=n;++i)
    {
        long long valc=(i*1LL*(i-1)/2)%mod;
        ans=(ans+v[i]*1LL*put10[n-i]%mod*1LL*valc)%mod;
    }
    cout<<ans;
    return 0;
}