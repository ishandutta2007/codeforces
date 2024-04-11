#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long put9[10],put10[200005];
int main()
{
    int t,i,j,n,m,cnt=0;
    cin>>n;
    put9[0]=put10[0]=1;
    for(i=1;i<=8;++i)
        put9[i]=(9LL*put9[i-1])%mod;
    for(i=1;i<=n;++i)
        put10[i]=(10LL*put10[i-1])%mod;
    for(i=1;i<n;++i)
        cout<<(10LL*(2LL*put10[n-i-1]*9LL)%mod+((((n-i-1)*1LL*put9[2])%mod)*10LL%mod*((put10[n-i-2])%mod))%mod)%mod<<' ';
    cout<<10;
    return 0;
}