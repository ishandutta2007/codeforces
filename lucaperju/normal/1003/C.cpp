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
int v[5005];
double verif (long long i, long long j)
{
    double s=v[j]-v[i-1],val=j-i+1;
    return s/val;
}
int main()
{
    long long t,i,j=0,n,c,dif,ok,rad,s=0,x,k,jdr=1,s1=0;
    double mx=0,a,b;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(i=1;i<=n;++i)
    {
        for(j=i+k-1;j<=n;++j)
        {
            a=verif(i,j);
            if(a>mx)
                mx=a;
        }
    }
    cout<<std::setprecision(16)<<mx;
    return 0;
}