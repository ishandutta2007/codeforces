#include <bits/stdc++.h>
using namespace std;
long long fct[250004];
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,i,mod;
    cin>>n>>mod;
    fct[1]=fct[0]=1;
    for(i=2;i<=n;++i)
        fct[i]=(fct[i-1]*1LL*i)%mod;
    long long s=0;
    for(i=0;i<n;++i)
        s=(s+(((((n-i)*1LL*(n-i))%mod*1LL*fct[i+1])%mod)*1LL*fct[n-i-1])%mod)%mod;
    cout<<s;
    return 0;
}