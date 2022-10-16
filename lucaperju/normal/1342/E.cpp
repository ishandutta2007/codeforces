#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long fact[200005];
long long factinv[200005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1LL)
        {
            --exp;
            rz=(rz*1LL*a)%mod;
        }
        else
        {
            exp>>=1LL;
            a=(a*1LL*a)%mod;
        }
    }
    return rz;
}
/// C(a,b) = n!/(k!*(n-k)!
long long comb (long long a, long long b)
{
    return ((fact[a]*factinv[b])%mod*factinv[a-b])%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long k,mxc=0,n,m,a,b,i,j=0,t;
	cin>>n>>k;
	fact[0]=fact[1]=1;
	for(i=2;i<=n;++i)
	    fact[i]=(fact[i-1]*i)%mod;
    for(i=1;i<=n;++i)
        factinv[i]=lgput(fact[i],mod-2);
    factinv[0]=factinv[1];
    if(k>=n)
    {
        cout<<0;
        return 0;
    }
    long long rz=0;
   // rz=comb(n,n-k);
    k=n-k;
    for(i=0;i<=k;++i)
    {
        if(i&1)
        {
            rz=(rz+mod-comb(k,i)*lgput(k-i,n))%mod;
        }
        else
        {
            rz=(rz+comb(k,i)*lgput(k-i,n))%mod;
        }
    }
    rz=(rz*comb(n,n-k))%mod;
    if(k!=n)
        cout<<(rz*2LL)%mod;
    else
        cout<<rz;
    return 0;
}