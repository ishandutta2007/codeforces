#include <bits/stdc++.h>

using namespace std;
const int mod=998244353;
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            rz=(rz*1LL*a)%mod;
            --exp;
        }
        else
        {
            a=(a*1LL*a)%mod;
            exp>>=1;
        }
    }
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long sus=1,jos=1;
    /// C(m,n-1);
    int i;
    for(i=m;i>=m-(n-1)+1;--i)
        sus=(sus*1LL*i)%mod;
    for(i=1;i<=n-1;++i)
        jos=(jos*1LL*i)%mod;
    sus=(sus*1LL*lgput(jos,mod-2))%mod;
    for(i=1;i<=n-3;++i)
        sus=(sus*2LL)%mod;
    sus=(sus*(n-2LL))%mod;
    cout<<sus;
    return 0;
}