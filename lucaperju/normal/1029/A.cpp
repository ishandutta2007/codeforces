#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
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
    long long n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,s=0,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    char c[55];
    cin>>n>>k>>ws;
    cin>>c;
    for(j=1;j<n;++j)
    {
        i=0;
        for(cj=j;cj<n;++cj,++i)
            if(c[i]!=c[cj])
                break;
        if(cj==n)
            break;
    }
  //  if(j==n)
  //      j=1;
    cout<<c;
    for(cj=1;cj<k;++cj)
        for(i=n-j;i<n;++i)
            cout<<c[i];
    return 0;
}