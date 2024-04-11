#include <iostream>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
long long v1[52],v2[52];
int main()
{
    long long m,n,i,j,k,a,b,mn=1000000000000000000LL,mxc=-1000000000000000000LL;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v1[i];
    for(i=1;i<=m;++i)
        cin>>v2[i];
    for(i=1;i<=n;++i)
    {
        mxc=-1000000000000000000LL;
        for(k=1;k<=n;++k)
        {
            if(k!=i)
            {
                for(j=1;j<=m;++j)
                {
                    if(v1[k]*1LL*v2[j]>mxc)
                        mxc=v1[k]*1LL*v2[j];
                }
            }
        }
        if(mxc<mn)
            mn=mxc;
    }
    cout<<mn;
    return 0;
}