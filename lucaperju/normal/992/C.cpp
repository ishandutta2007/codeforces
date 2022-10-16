#include <iostream>

using namespace std;
const long long mod=1000000007;
long long lgput (long long val, long long jos)
{
    long long N=jos,P=val,r=1LL;
    if(P==0)
        return 1;
    while(P!=1LL)
    {
        if(!(P&1LL))
        {
            P>>=1LL;
            N=N*1LL*N%mod;
        }
        else
        {
            P=P-1LL;
            r=r*1LL*N%mod;
        }
    }
    N=N*1LL*r%mod;
    return N%mod;
}
int main()
{
    long long n,k,n1,n2,p;
    cin>>n>>k;
    if(n==0)
        cout<<0;
    else if(k==0)
    {
        n=n%mod;
        n=n*1LL*2LL%mod;
        cout<<n%mod;
    }
    else
    {
        p=lgput(k,2LL);
        p=(long long)p%mod;
        n=n%mod;
        n=n*1LL*p%mod;
        n=n*1LL*2LL%mod;
   //     n=(long long)(n-p+mod)%mod;
        n=(long long)n-p;
        n=(long long)(n+mod*1LL*2LL)%mod;
        n=(n+1LL)%mod;
        cout<<n%mod;
    }
    return 0;
}