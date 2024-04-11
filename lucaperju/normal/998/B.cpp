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
int v[105],rezct[105];
int main()
{
    long long i,j=0,n,a,b,mx1=-1,mx2=-1,rez=-1,rezi,cr,init=0,pz;
    cin>>n>>b;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(init==0 && i!=1)
            rezct[++j]=max(v[i]-v[i-1],v[i-1]-v[i]);
        if(v[i]%2==1)
            ++init;
        else
            --init;
    }
    init=cr=0;
    sort(rezct+1,rezct+j+1);
    for(i=1;i<=j;++i)
    {
        init+=rezct[i];
        if(init<=b)
            ++cr;
        else
            break;
    }
    cout<<cr;
    return 0;
}