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
char v1[105],v2[105];
int main()
{
    long long i,j,a,b=-1,c,x=1000000000,y,mx=-10000000000,ln,cl,lnp,clp;
    cin>>v1>>v2;
    a=strlen(v1);
    cout<<v1[0];
    for(i=1;i<a;++i)
    {
        if(v1[i]<v2[0])
            cout<<v1[i];
        else
            break;
    }
    cout<<v2[0];
    return 0;
}