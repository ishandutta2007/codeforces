#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
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
    long long t,i,j=1,n,a,b,c,dif,ok,rad;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cin>>a;
        ok=1;
        for(n=1;n==1 || n*n-(n/2)*(n/2)<=a;++n)
        {
            long long dif=n*n-a;
            if(dif<0)
                continue;
            rad=sqrt(dif);
            if(rad*rad!=dif || rad==0)
                continue;
            b=n/rad;
            if(b>0 && n*n-(n/b)*(n/b)==a)
            {
                ok=0;
                cout<<n<<' '<<b<<'\n';
                break;
            }
        }
        if(ok==1)
            cout<<-1<<'\n';
    }
    return 0;
}