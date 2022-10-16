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
int v[300005],cat[300005];
int main()
{
    long long i,j=1,n,a,b,mx1=-1,mx2=-1,rez=0,rezi,cr,init=0,pz;
    char c;
    cin>>n>>a>>b;
    for(i=1;i<=n;++i)
    {
        cin>>c;
        v[i]=c-'0';
        if(v[i]==v[i-1] || i==1)
        {
            ++cat[j];
        }
        else
        {
            ++cat[++j];
        }
    }
    if(v[1]==1)
        i=2;
    else
        i=1;
    for(;i<=j;i+=2)
        rez+=min(a,b);
    if(j==1 && v[1]==1)
    {
        cout<<0;
        return 0;
    }
    if(a<b)
    {
        rez+=b-a;
    }
    cout<<rez;
    return 0;
}