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
    long long n,i,j,a,b,c=0;
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    for(i=a,j=b;i<=j;++i,--j)
    {
        c+=i-a;
        c+=b-j;
        if(i==j-1)
        {
            c+=b-i;
        }
    }
    cout<<c;
    return 0;
}