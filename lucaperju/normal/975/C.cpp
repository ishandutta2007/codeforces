#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
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
long long sp[200005],n;
void caut (long long val)
{
    long long pas=1<<30,k=0;
    while(pas)
    {
        if(k+pas<=n && sp[k+pas]<=val)
            k+=pas;
        pas>>=1;
    }
    cout<<n-k<<'\n';
}
int main()
{
    long long t,i,j=0,c,dif,ok,rad,sc=0,x,k,jdr=1,s1=0,mx=0,d,a,b,y,m;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>sp[i];
        sp[i]+=sp[i-1];
    }
    for(i=1;i<=m;++i)
    {
        cin>>a;
        sc+=a;
        if(sc>=sp[n])
            sc=0;
        caut(sc);
    }
    return 0;
}