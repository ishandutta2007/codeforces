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
int main()
{
    long long n,i,j,a,b,c,d;
    cin>>a>>b>>c>>d;
    a-=c;
    b-=c;
    if(a<0 || b<0)
    {
        cout<<-1;
        return 0;
    }
    a=a+b+c;
    if(a<d)
        cout<<d-a;
    else
        cout<<-1;
    return 0;
}