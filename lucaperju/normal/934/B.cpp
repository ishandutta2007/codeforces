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
    long long k;
    cin>>k;
    if(k>36)
    {
        cout<<-1;
        return 0;
    }
    while(k>1)
    {
        cout<<8;
        k-=2;
    }
    if(k)
        cout<<4;
    return 0;
}