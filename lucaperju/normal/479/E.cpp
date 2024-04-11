#include <iostream>
#include <vector>
using namespace std;
const int mod=(1e9)+7;
int d[5005],dn[5005];
int main()
{
    int k,a,b,t,n,i,j,s=0;
    cin>>n>>a>>b>>k;
    d[a]=1;
    while(k--)
    {
        for(i=1;i<=n;++i)
        {
            if(i==b)
                continue;
            int dst=max(b-i,i-b);
            if(dst==1)
                continue;
            dn[max(1,i-dst+1)]=(dn[max(1,i-dst+1)]+d[i])%mod;
            dn[i]=(dn[i]-d[i]+mod)%mod;
            dn[i+1]=(dn[i+1]+d[i])%mod;
            dn[min(i+dst,n+1)]=(dn[min(i+dst,n)]-d[i]+mod)%mod;
        }
        for(i=1;i<=n;++i)
            dn[i]=(dn[i]+dn[i-1])%mod;
        for(i=1;i<=n;++i)
        {
            d[i]=dn[i];
            dn[i]=0;
        }
    }
    for(i=1;i<=n;++i)
        s=(s+d[i])%mod;
    cout<<s;
    return 0;
}