#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long v[300003];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1LL)
        {
            rz=(rz*1LL*a)%mod;
            --exp;
        }
        else
        {
            exp>>=1LL;
            a=(a*1LL*a)%mod;
        }
    }
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,m,i,t,j,k=0;
    cin>>n;
    for(i=1;i<=n*2;++i)
        cin>>v[i];
    sort(v+1,v+n+n+1);
    long long jos=1,sus=1;
    for(i=1;i<=n;++i)
    {
        jos=jos*1LL*i%mod;
    }
    for(i=n+1;i<=2*n;++i)
    {
        sus=sus*1LL*i%mod;
    }
    jos=lgput(jos,mod-2);
    long long rzc=(sus*1LL*jos)%mod;
    long long rz=0;
    for(i=1;i<=n;++i)
        rz=(rz-(v[i]*1LL*rzc)%mod+mod)%mod;
    for(i=n+1;i<=n+n;++i)
        rz=(rz+(v[i]*1LL*rzc)%mod)%mod;
    cout<<rz;
    return 0;
}