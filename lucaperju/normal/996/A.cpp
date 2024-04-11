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
/*
for(i=1;i<=n;++i)
*/
int main()
{
    long long n,i,j,a,b,c,mx=-1000000000000000000,mn=1000000000000000000,s=0;
    cin>>n;
    while(n)
    {
        if(n>=100)
        {
            s+=n/100;
            n-=100*(n/100);
        }
        else
        if(n>=20)
        {
            s+=n/20;
            n-=20*(n/20);
        }
        else
        if(n>=10)
        {
            s+=n/10;
            n-=10*(n/10);
        }
        else
        if(n>=5)
        {
            s+=n/5;
            n-=5*(n/5);
        }
        else
        {
            s+=n;
            break;
        }
    }
    cout<<s;
    return 0;
}