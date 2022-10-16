#include <iostream>
#include <cstring>
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
for(i=1;i<=n;++i)...
*/
int v[105][105];
int main()
{
    long long n,i,j=-2,a,b,c,cat=0;
    cin>>n>>a>>b;
    if(a>b)
        swap(a,b);
    if(a<=n/2 && b>n/2)
    {
        cout<<"Final!";
        return 0;
    }
    c=n;
    while(c)
    {
        ++j;
        c/=2;
    }
    for(i=j;i>=1;--i)
    {
        n/=2;
        if(a>n)
        {
            a-=n;
            b-=n;
        }
        if(a<=n/2 && b>n/2)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}