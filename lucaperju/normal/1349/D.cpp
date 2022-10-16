#include <bits/stdc++.h>
using namespace std;
long long f[300003],inv[300003],v[300003];
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long m=0,i,j,n;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        m+=v[i];
    }
    inv[1]=1;
    for(i=2;i<=max(n,m);++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod;
    f[0]=f[1]=0;
    for(i=1;i<m;++i)
        f[i+1]=(n-1)*1LL*(inv[m-i])%mod*1LL*((f[i]*1LL*m%mod-i*1LL*(f[i-1]+1)%mod+mod)%mod-(m-i)*1LL*(n-2)%mod*1LL*inv[n-1]%mod*1LL*f[i]%mod+mod)%mod;
    long long ans=0;
    for(i=1;i<=n;++i)
        ans=ans+f[v[i]];
    ans=(ans-f[m]+mod)%mod;
    cout<<ans;
    return 0;
}