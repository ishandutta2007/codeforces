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
char v[105];
int main()
{
    long long n,i,j,a,b,c,mx=-2250000000000,mn=-2250000000000,s=0,cat,xc=0,yc=0,xc1=0,yc1=0,xc2=0,yc2=0;
    cin>>n;
    cin>>(v+1);
    s=n;
    for(i=1;i<=n;++i)
    {
        int ok=1;
        for(j=i+1;j<=2*i;++j)
        {
            if(v[j-i]!=v[j])
                ok=0;
        }
        if(ok==1)
            mx=i-1;
    }
    if(mx<-100000)
        mx=0;
    cout<<s-mx;
    return 0;
}